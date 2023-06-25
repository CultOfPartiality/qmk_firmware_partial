# Userspace - CultOfPartiality
Sick of copying settings from keyboard to keyboard as I keep developing my own layout, I've put all the common layout, code and settings into this userspace as QMK allows. Now, whenever I compile a board with the keymap of "cultofpartiality" this userspace will get included automatically.

## TODO
- Combine user functions (such as adjust layer) into userspace rather than repeating in each keyboard
- Fix planck numbers + symbols
- Might be good to have a permenant caps lock option, and maybe allow cancelling it with escape?
- More layers, accessable to the thumbs on space/enter?
    - Getting a sore hand when holding nav key (an inwards movement). Others solve this with alternating hands, but single hand nav is too important I think
    - There's an idea, mouse mode with right hand movement, left hand click?
- Live definable macros

## Standardised Layouts
So far I've only got this done for the navigation/raise layer, and only the "inner block" of keys (all those reached one up or down from the eight finger home positions, and the index fingers' inner row). This means the arrow keys, mouse mode keys, and other useful nav keys are always in the same place.

I'd like to start doing this for the symbols/lower layer, but the Planck's number row that I'm currently set on has made that difficult. Hopefully next time I come back to update this doco I'll have some sort of fix for this, which I'm suspecting will be to move the "[" and "]" key down to below the home row rather than above it. Then again, that muscle memory will take a little bit to break.

- 25/06/2023 - Commenced setting out to move the planck number layer


## Standard settings
### Mouse Mode
Mouse mode has a number of tuning components for speed and accdeleration and delays. As such, when I finally sit down to tune these to work smoothly I'd want these to propagate to the other boards.

These keys are included in the standardised NAV layer.

### Auto Shift
Hold a key to get it's shifted form.

Not sure how I feel about this one all the time, as it seems to cause some issues on occasions.

### Caps Word
Press both shifts, and trigger "caps lock" until the end of the current word. Pretty neat, although I need to remember it's there more often.
