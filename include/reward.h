#ifndef REWARD_H
#define REWARD_H

// Design a class Reward which can take one of four possible values from 1 to 4 rubies. 
// A reward must also be printable with the insertion operator cout << reward.
class Reward {
    private:
        int rubies;

        Reward() {};
        Reward(int r): rubies(r) {};
        ~Reward() {};

    public:
        // An object of type Reward can not be copied or assigned and needs a private constructor 
        // but will give RewardDeck (see below) friend access.
        inline int getRubies() const { return rubies; }
        friend std::ostream& operator<<(std::ostream & os, const Reward & r);
        inline operator int() const { return rubies; }
};

#endif
