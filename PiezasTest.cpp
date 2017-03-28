/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, checkContructor) {
	Piezas g;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			ASSERT_EQ(g.pieceAt(i, j), Blank);
		}
	}
}

TEST(PiezasTest, checkReset) {
	Piezas g;
	g.reset();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			ASSERT_EQ(g.pieceAt(i, j), Blank);
		}
	}
}

TEST(PiezasTest, checkResetFullBoardEmpty) {
	// finish this later
}

TEST(PiezasTest, checkPieceX) {
	Piezas g;
	ASSERT_EQ(g.dropPiece(0), X);
}

TEST(PiezasTest, checkPieceO) {
	Piezas g;
	g.dropPiece(0);
	ASSERT_EQ(g.dropPiece(1), O);
}

TEST(PiezasTest, checkPieceXat00) {
	Piezas g;
	g.dropPiece(0);
	ASSERT_EQ(g.pieceAt(0, 0), X);
}

TEST(PiezasTest, checkDropPieceX03) {
	Piezas g;
	g.dropPiece(3);
	ASSERT_EQ(g.pieceAt(0, 3), X);
}

TEST(PiezasTest, checkPieceXat20) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(0);
	ASSERT_EQ(g.pieceAt(2, 0), X);
}

TEST(PiezasTest, checkPieceXat23) {
	Piezas g;
	g.dropPiece(3);
	g.dropPiece(3);
	g.dropPiece(3);
	ASSERT_EQ(g.pieceAt(2, 3), X);
}

TEST(PiezasTest, checkPieceOat00) {
	Piezas g;
	g.dropPiece(1);
	g.dropPiece(0);
	ASSERT_EQ(g.pieceAt(0, 0), O);
}

TEST(PiezasTest, checkPieceOat03) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(3);
	ASSERT_EQ(g.pieceAt(0, 3), O);
}

TEST(PiezasTest, checkPieceOat20) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(1);
	g.dropPiece(0);
	ASSERT_EQ(g.pieceAt(2, 0), O);
}

TEST(PiezasTest, checkPieceOat23) {
	Piezas g;
	g.dropPiece(3);
	g.dropPiece(3);
	g.dropPiece(0);
	g.dropPiece(3);
	ASSERT_EQ(g.pieceAt(2, 3), O);
}

TEST(PiezasTest, checkInvalidPieceXCol) {
	Piezas g;
	ASSERT_EQ(g.dropPiece(-1), Invalid);
}

TEST(PiezasTest, checkInvalidPieceOCol) {
	Piezas g;
	g.dropPiece(0);
	ASSERT_EQ(g.dropPiece(-1), Invalid);
}

TEST(PiezasTest, checkInvalidPieceXColAbove) {
	Piezas g;
	ASSERT_EQ(g.dropPiece(4), Invalid);
}

TEST(PiezasTest, checkInvalidPieceOColAbove) {
	Piezas g;
	g.dropPiece(0);
	ASSERT_EQ(g.dropPiece(4), Invalid);
}

TEST(PiezasTest, checkInvalidPieceXRowAbove) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(0);
	ASSERT_EQ(g.dropPiece(0), Blank);
}

TEST(PiezasTest, checkInvalidPieceORowAbove) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(1);
	ASSERT_EQ(g.dropPiece(0), Blank);
}

TEST(PiezasTest, checkInvalidgameState) {
	Piezas g;
	g.dropPiece(0);
	ASSERT_EQ(g.gameState(), Invalid);
}

TEST(PiezasTest, checkXWinnerVert3) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(1);
	g.dropPiece(0);
	g.dropPiece(2);
	g.dropPiece(0);
	g.dropPiece(2);
	g.dropPiece(1);
	g.dropPiece(1);
	g.dropPiece(3);
	g.dropPiece(3);
	g.dropPiece(2);
	g.dropPiece(3);
	ASSERT_EQ(g.gameState(), X);
}

TEST(PiezasTest, checkOWinnerVert3) {
	Piezas g;
	g.dropPiece(1);
	g.dropPiece(3);
	g.dropPiece(2);
	g.dropPiece(3);
	g.dropPiece(1);
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(2);
	g.dropPiece(0);
	g.dropPiece(3);
	g.dropPiece(2);
	g.dropPiece(1);
	ASSERT_EQ(g.gameState(), O);
}

TEST(PiezasTest, checkOWinnerHoriz3) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(1);
	g.dropPiece(1);
	g.dropPiece(3);
	g.dropPiece(2);
	g.dropPiece(3);
	g.dropPiece(2);
	g.dropPiece(0);
	g.dropPiece(1);
	g.dropPiece(2);
	g.dropPiece(3);
	ASSERT_EQ(g.gameState(), O);
}

TEST(PiezasTest, checkXWinnerHoriz3) {
	Piezas g;
	g.dropPiece(3);
	g.dropPiece(2);
	g.dropPiece(3);
	g.dropPiece(1);
	g.dropPiece(2);
	g.dropPiece(3);
	g.dropPiece(1);
	g.dropPiece(2);
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(1);
	g.dropPiece(0);
	ASSERT_EQ(g.gameState(), X);
}

TEST(PiezasTest, checkXWinnerHoriz4) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(1);
	g.dropPiece(1);
	g.dropPiece(2);
	g.dropPiece(2);
	g.dropPiece(3);
	g.dropPiece(0);
	g.dropPiece(3);
	g.dropPiece(2);
	g.dropPiece(1);
	g.dropPiece(3);
	ASSERT_EQ(g.gameState(), X);
}

TEST(PiezasTest, checkOWinnerHoriz4) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(1);
	g.dropPiece(1);
	g.dropPiece(2);
	g.dropPiece(2);
	g.dropPiece(0);
	g.dropPiece(3);
	g.dropPiece(1);
	g.dropPiece(3);
	g.dropPiece(2);
	g.dropPiece(3);
	ASSERT_EQ(g.gameState(), O);
}

TEST(PiezasTest, checkTie) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(1);
	g.dropPiece(1);
	g.dropPiece(1);
	g.dropPiece(2);
	g.dropPiece(2);
	g.dropPiece(2);
	g.dropPiece(3);
	g.dropPiece(3);
	g.dropPiece(3);
	ASSERT_EQ(g.gameState(), Blank);
}

TEST(PiezasTest, checkTie2) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(2);
	g.dropPiece(1);
	g.dropPiece(3);
	g.dropPiece(0);
	g.dropPiece(2);
	g.dropPiece(1);
	g.dropPiece(3);
	g.dropPiece(2);
	g.dropPiece(0);
	g.dropPiece(3);
	g.dropPiece(1);
	ASSERT_EQ(g.gameState(), Blank);
}

TEST(PiezasTest, checkTie4) {
	Piezas g;
	g.dropPiece(0);
	g.dropPiece(0);
	g.dropPiece(1);
	g.dropPiece(1);
	g.dropPiece(2);
	g.dropPiece(2);
	g.dropPiece(3);
	g.dropPiece(3);
	g.dropPiece(0);
	g.dropPiece(1);
	g.dropPiece(2);
	g.dropPiece(3);
	ASSERT_EQ(g.gameState(), Blank);
}
