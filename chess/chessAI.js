// const { move } = require("fs-plus")

var board = null
var game = new Chess()
var whiteSquareGrey = '#a9a9a9'
var blackSquareGrey = '#696969'
var maxDepth = 3
var $board = $('#myBoard')
var squareClass = 'square-55d63'

function removeGreySquares() {
    $('#myBoard .square-55d63').css('background', '')
}

function removeGreySquare(square) {
    var $square = $('#myBoard .square-' + square)

    var background = whiteSquareGrey
    if ($square.hasClass('black-3c85d')) {
        background = 'white'
    }

    $square.css('background', '')
}

function greySquare(square) {
    var $square = $('#myBoard .square-' + square)

    var background = whiteSquareGrey
    if ($square.hasClass('black-3c85d')) {
        background = blackSquareGrey
    }

    $square.css('background', background)
}
function highlight(square) {
    var $square = $('#myBoard .square-' + square)

    var background = 'blue'
    if ($square.hasClass('black-3c85d')) {
        background = 'red'
    }

    $square.css('background', background)
}

function onDragStart(source, piece) {
    // do not pick up pieces if the game is over
    if (game.game_over()) return false

    // or if it's not that side's turn
    if ((game.turn() === 'w' && piece.search(/^b/) !== -1) ||
        (game.turn() === 'b' && piece.search(/^w/) !== -1)) {
        return false
    }
}

function onDrop(source, target) {
    // removeGreySquares()
    var moves = game.moves({
        square: source,
        verbose: true
    })

    // exit if there are no moves available for this square
    if (moves.length === 0) return

    // highlight the square they moused over
    removeGreySquare(source)

    // highlight the possible squares for this piece
    for (var i = 0; i < moves.length; i++) {
        console.log(moves[i].to);
        removeGreySquare(moves[i].to)
    }
    if(source == target){
        return 'snapback';
    }

    // see if the move is legal
    var move = game.move({
        from: source,
        to: target,
        promotion: 'q' // NOTE: always promote to a queen for example simplicity
    })
    
    // illegal move
    if (move === null) return 'snapback'
}

function onMouseoverSquare(square, piece) {
    // get list of possible moves for this square
    var moves = game.moves({
        square: square,
        verbose: true
    })

    // exit if there are no moves available for this square
    if (moves.length === 0) return

    // highlight the square they moused over
    greySquare(square)

    // highlight the possible squares for this piece
    for (var i = 0; i < moves.length; i++) {
        console.log(moves[i].to);
        greySquare(moves[i].to)
    }
}

function onMouseoutSquare(square, piece) {
    // removeGreySquares(square)
    // get list of possible moves for this square
    var moves = game.moves({
        square: square,
        verbose: true
    })

    // exit if there are no moves available for this square
    if (moves.length === 0) return

    // highlight the square they moused over
    // greySquare(square)

    // highlight the possible squares for this piece
    for (var i = 0; i < moves.length; i++) {
        console.log(moves[i].to);
        removeGreySquare(moves[i].to)
    }
    removeGreySquare(square);
}

function onSnapEnd() {
    removeGreySquares()
    // console.log(game.moves())
    let aiMove;
    aiMove = minimax(1, true, 0);
    // let allMoves = game.moves();
    // let move = allMoves[aiMove];
    let move = game.move(aiMove);
    console.log(move);
    board.position(game.fen());
    console.log(move.to);
    
    highlight(move.to);
    highlight(move.from);
}

var config = {
    draggable: true,
    position: 'start',
    onDragStart: onDragStart,
    onDrop: onDrop,
    onMouseoutSquare: onMouseoutSquare,
    onMouseoverSquare: onMouseoverSquare,
    onSnapEnd: onSnapEnd
}
board = Chessboard('myBoard', config)

function minimax(d, isMax, value){
    if(d == maxDepth){
        return value;
    }
    let ans;
    let bestMove;
    if(isMax == true){
        ans = Number.NEGATIVE_INFINITY;
    } else {
        ans = Number.POSITIVE_INFINITY;
    }
    let allMoves = game.moves();

    for(key in allMoves){
        let move = allMoves[key]
        // console.log(move);
        let thisMove = game.move(move);
        console.log(thisMove);
        // console.log(thisMove.captured);
        let action = evaluate(thisMove.captured);
        if(isMax == true){
            let tempValue = minimax(d+1, !isMax, value + action);
            if(ans < tempValue){
                ans = tempValue;
                bestMove = move;
            }
        } else {
            let tempValue = minimax(d+1, !isMax, value - action);
            if(ans > tempValue){
                ans = tempValue;
                bestMove = move;
            }
        }
        game.undo()
    }
    if(d == 1){
        return bestMove; 
    } else {
        return ans;
    }

}

function evaluate(str){
    let action = 0
    switch(str){
        case 'p': {
            action = 10;
        };
        break;
        case 'n': {
            action = 30;
        };
        break;
        case 'b': {
            action = 30;
        };
        break;
        case 'r': {
            action = 50;
        };
        break;
        case 'q': {
            action = 100;
        };
        break;
        case 'k': {
            action = 900;
        };
        break;
        default: {
            action = 0;
        }
    }
    if(game.in_checkmate()){
        return 900000;
    }
    return action
}

$('#undoButton').on('click', (event)=>{
    console.log(event);
    game.undo();
    game.undo();
    board.position(game.fen());
})
