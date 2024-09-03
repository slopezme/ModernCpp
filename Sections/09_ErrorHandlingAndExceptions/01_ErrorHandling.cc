/*####################
# Error Handling
####################*/

/*
Even perfect code may suffer from errors in the real world
- Trying to read a file that does not exist
- Trying to send data over a network coneection that is down
- Receiving data which is incorrect or in the wrong format

There are situations which arise at runtime when the environment does not behave as expected

In basic programas, we can just print out
A serious programas, we need to do better


*/

/*####################
# Error Communication
####################*/

/*
Communcate with the user
- Tell user that the problem is and what they can do about it
- Give opportunity to retru, solve, or ignore as appropriate
- If necesessary, notify other concerned parties

Avoid information which is not helpful to the user
- "Error xxxx occurred. Please consult the manual"
- Java stack trace

Only exit the program as a last resort
*/

/*####################
# Where to Handle Errors
####################*/

/*
- Ofthen, errors can be handled where they occur
- Sometimes, it is useful to handle errors in a different part
 of the code from where the error occurs

 - e.g. if we want to display a dialogue box whent there is an error in a file download

 - We should not mix up GUI code with networking code
    - It makes the code more complicated
    - The error handling code is a distraction from the nwetworking logic
    - Eror handling code is spread all over the program

*/

/*####################
# Higher level error handling
####################*/

/*
A better apprograch is to have these errors handled at a higher level
    - If we have an error which needs to be handled with GUI code, this should go
    in the user interface part of the code

The error needs to be passes from the place where the error occurred to the code
that handles it

*/