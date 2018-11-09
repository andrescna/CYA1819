#include "wall.hpp"


//////// class wall methods

wall::wall()
{
    wallLenght = 1;
    wallHeight = 1;
}


wall::wall(int l, int h)
{
    wallLenght = l;
    wallHeight = h;
}


void wall::insert_row(row lastRow)
{
    wall_.push_back(lastRow);
}

void wall::erase_row()
{
    wall_.pop_back();
}


int wall::get_height()
{
    return wallHeight;
}

int wall::get_length()
{
    return wallLenght;
}

int wall::get_wall_rows()
{
    return wall_.size();
}

void wall::clear_rows()
{
    wall_.clear();

}


ostream& wall::write(ostream& os){

    for (int i=0; i<wallHeight; i++){
        wall_[i].write(os);
    }

    cout << endl; 
    return os;
}


wall::~wall(){}


////// Outside methods

//////////////////////////////////////////// Calculates all valid walls with a precalculated valid rows set

vector<wall> calc_valid_walls(vector<row> validRows, int wallLength, int wallHeight)
{
    vector<wall> validWalls;
    wall temp(wallLength,wallHeight);

    for (int i=0; i < validRows.size(); i++){
        bool isinserted = false;
        calc_row_order(validWalls, validRows, temp, i, isinserted);
    }

    return validWalls;
}

// Main wall calculation function.

void calc_row_order(vector<wall> &validWalls, vector<row> validRows, wall temp, int i, bool isinserted)
{
    temp.insert_row(validRows[i]);

    if ((temp.get_wall_rows() == temp.get_height()) && (isinserted == false)){
            validWalls.push_back(temp);
            isinserted = true;
    }

    else if (temp.get_wall_rows() < temp.get_height()) {
            for (int j=0; (j<validRows.size()); j++){
                    
                    if (j != i){
                    // quiero comprobar si es válida
                    
                            int k = 0;
                            int l = 0;
                            bool isthisrowvalid = true;

                            while (isthisrowvalid == true && k<validRows[i].get_row_size() && l<validRows[j].get_row_size()){

                                int b1 = validRows[i].get_row_element(k);
                                int b2 = validRows[j].get_row_element(l);

                                if ((b1 == b2) && (b1 != 0) && (b1 != temp.get_length())) {
                                        isthisrowvalid = false;
                                }
                                
                                if (b2 > b1){
                                    k++;
                                } 
                                else 
                                    l++;

                            }
 
                            if ((isthisrowvalid == true) && (temp.get_wall_rows() < temp.get_height())){

                                        calc_row_order(validWalls, validRows, temp, j, isinserted);
                            }
                    }
            }
    }   
}
    