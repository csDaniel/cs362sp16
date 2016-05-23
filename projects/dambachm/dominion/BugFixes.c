/*
 * Both of my team mates reported the same defects. Since they were the same defects I had intentionally
 * introduced for a prior assignment, finding and fixing them were pretty simple.
 *
 * The first defect was on the playSmithy function. The for loop to draw a card was "for (i = 0; i <= 3; i++)"
 * This caused four cards to be drawn instead of the correct amount of three cards. I removed the "=" to make it
 * "for (i = 0; i < 3; i++)".
 *
 * The second defect was due to the playAdventurer function not checking if the cardDrawn was silver. It
 * only checked if the card was a copper or a gold. This had the effect of treating the silver card as
 * any other ordinary card instead of a treasury card. To correct this, I simply change the condition
 * "if (cardDrawn == copper ||  cardDrawn == gold)" to "if (cardDrawn == copper ||  cardDrawn == silver ||
 * cardDrawn == gold)".
 *
 *
 */

