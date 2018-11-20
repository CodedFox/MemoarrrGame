#ifndef REWARD_H
#define REWARD_H

// Design a class Reward which can take one of four possible values from 1 to 4 rubies. 
// A reward must also be printable with the insertion operator cout << reward.
class Reward {
    private:
        int numRubies; //one of four possible values from 1 to 4 rubies
        Reward();
        Reward(int);
    public:
        // An object of type Reward can not be copied or assigned and needs a private constructor 
        // but will give RewardDeck (see below) friend access.
        int getNumRubies() const; //return number of rubies for this reward
        //int conversion operator
        inline operator int(){ return numRubies;}
        friend std::ostream &operator<<(std::ostream &, const Reward &);
};


#endif
