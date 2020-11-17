### Describe the effect each of the P, I, D components had in your implementation.
- P : if I left the weight for P too low, the car wouldn't turn fast enough to handle some of the sharper corners. This makes sense, as P has the most obvious impact on turning the car.
- I : This seemed not that important, and in general a small weight would do. This makes sense as it is mainly to handle systematic errors.
- D : Important to tune, it would control how much the car oscillated. It is difficult to remove this entirely, and I notice that the car still has a slight oscillation behavior whenever it exits a turn.

### Describe how the final hyperparameters were chosen.

- First I used the twiddle implementation, starting with `{0.225, 0.004, 4.0}` as my parameters, and dp as 1/10th of these values
- However, I did notice that training of the twiddle algorithm was a little slow. I also tried using 1/5th of the values as dp, but the D component quickly deteriorated
- I picked one of the middle values from training `{0.126, 0.002, 2.5}`, and then manually tuned it afterwards, resulting in the final values of `{0.136,0.00032,1.4}`