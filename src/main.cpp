
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <iomanip>

int main(int argc, char* argv[])
{
 
  if(argc < 2) {
   std::cout << "no file found...\n";
   std::cout << "Press Enter to exit...\n";
   std::cin.get();
   return 1;
  }
    std::streampos start,end; 
    std::ifstream file (argv[1], std::ios::binary);
    

    if(!file) {
      std::cout << " bad pathing \n" ;
      std::cout << "Press Enter to exit...\n";
      std::cin.get();
      return 1;
    }
  
    start = file.tellg();
    file.seekg(0, std::ios::end);
    end = file.tellg();

   std::vector<uint8_t> bytes(static_cast<std::size_t>(end - start));


    file.seekg(0, std::ios::beg); 
    

    file.read(reinterpret_cast<char*>(bytes.data()), bytes.size());

    std::ofstream out("hex.txt");
  
    std::cout << "FILE: " << (argv[1]) << " \n";
    std::cout << "SIZE: " << bytes.size() << " bytes. \n";
    std::cout <<"HEX: \n"; 
      
      for (std::size_t i = 0; i < bytes.size(); i++)
      {

        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) << " ";
        
        out << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) << " ";

        if ((i + 1) % 16 == 0)
        {
          std::cout << '\n'; 
         out << '\n';

        } 
      
      }

    std::cin.get(); 

    return 0;
}  
