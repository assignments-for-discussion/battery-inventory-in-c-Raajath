#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
  int invalid;
//Added another variable invalid when test case is invalid
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0, 0 };

  for(int i=0;i<nBatteries;i++)
    {
      
         // Assume rated capacity is 120
    if(presentCapacities[i]>120||presentCapacities[i]<0)
    {
     printf("Invalid present Capacities");
      counts.invalid++;

    }

    else{
             //Calculating SoH percentage
         int ratedCapacity=120;
         double soh= ((100*presentCapacities[i])/ratedCapacity);

      if(soh>80.0)
      {
        counts.healthy++;
      }
      else if(soh<=80.0 && soh>=62.0)
      {
         counts.exchange++;
      }
      else
      {
        counts.failed++; 
      }

    }
        
    }
      
      
  
  return counts;
}

void testBucketingByHealth() {
  //modified test cases 
  // added test case where present capacity is greater than rated capacity 
  // added another test case where present capacity is zero
  // Where present capacity is negative
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70,0,122,-1};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 2);
  assert(counts.invalid==2);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
