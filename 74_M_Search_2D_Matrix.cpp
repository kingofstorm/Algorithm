class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		int row_i = 0;
		int row_j=matrix[0].size()-1;
		int colum_x = 0;
		int colum_y=matrix.size()-1;
		int col_middle=0;
		int row_middle=0;
		int tmp = 0;
		while (colum_x<colum_y)
		{
			col_middle = colum_x + (colum_y - colum_x) / 2;
			if (matrix[colum_x][0] <= target&&matrix[col_middle][0]>target)
			{
				tmp = colum_x;
				colum_y = col_middle - 1;
			}
			else if (matrix[col_middle][0] <= target&&matrix[colum_y][0]>target)
			{
				tmp = col_middle;
				colum_x = col_middle + 1;
			}
			else if (matrix[colum_y][0]<=target)
			{
				tmp = colum_y;
				break;
			}
			else
			{
				break;
			}

		}
	
		while (row_i<=row_j)
		{
			row_middle = row_i + (row_j - row_i) / 2;
			if (matrix[tmp][row_middle] == target)
				return true;
			if (matrix[tmp][row_middle] < target)
				row_i = row_middle + 1;
			else  
				row_j = row_middle - 1;
		}

		return false;
	}
};
