#include <cstdint>
#include <vector>

class AES {
    private: 
        uint8_t FFAddByte(uint8_t a, uint8_t b);          
        uint32_t FFAddWord(uint32_t a, uint32_t b);               
        uint8_t FFMultiply(uint8_t a, uint8_t b);             
        uint8_t XTime(uint8_t ff);                                 

        std::vector <uint8_t> RotWord(std::vector <uint8_t> word); 
        std::vector <uint8_t> SubWord(std::vector <uint8_t> word);   

        std::vector <uint8_t> asVector(uint32_t word);
        uint32_t asWord(std::vector <uint8_t> word);

        void AddRoundKey(uint8_t round);
        void InvMixColumns();                                       
        void InvShiftRows();                                        
        void InvSubBytes();                                         
        void MixColumns();                                                                                    
        void ShiftRows();                                          
        void SubBytes();
        
        int Nb;      // Number of 32-bit words in the state, 4
        int Nk;      // Number of 32-bit words comprising the Cipher Key, 4, 6, or 8
        int Nr;      // Number of rounds, 10, 12, or 14
        
        std::vector <uint32_t> Rcon;
        std::vector <uint32_t> key;

        //Handles the final Sbox conversion
        std::vector <std::vector<uint8_t> > state;
        std::vector <std::vector<uint8_t> > Sbox;
        std::vector <std::vector<uint8_t> > InvSbox;

    public:
        AES( std::vector <std::vector<uint8_t> > plaintext, 
             std::vector <uint32_t> origKey,
             int keysize );
        std::vector <std::vector<uint8_t> > getState();

        //Links
        friend class AESWorker;
        friend class AESUnitTests;
};