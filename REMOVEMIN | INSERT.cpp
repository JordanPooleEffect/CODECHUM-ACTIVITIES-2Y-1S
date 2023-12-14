int removeMin() {
        list->swap(0,list->size()-1);
        int removeElem = list->removeLast();
        int smallest = 0;

        while (true) {
            int smallestNumber = smallest;
            int left = (smallestNumber * 2) + 1;
            int right = (smallestNumber * 2) + 2;

            if(list->get(smallestNumber+1) > list->get(left+1) && left < list->size()) {
                smallestNumber = (smallest * 2) + 1;
            }

            if(list->get(smallestNumber+1) > list->get(right+1) && right < list->size()) {
                smallestNumber = (smallest * 2) + 2;
            }

            if (smallestNumber != smallest) {
                list->swap(smallest, smallestNumber);
                smallest = smallestNumber;
            } else {
                break;
            }
        }
    }

    void insert(int num) {
		list->add(num);
		int curr_ind = list->size()-1;
		int par_ind = (curr_ind-1) / 2;
		while (list->get(curr_ind+1) < list->get(par_ind+1)) {
			list->swap(curr_ind, par_ind);
			curr_ind = par_ind;
			par_ind = (curr_ind-1) / 2;
		}
	}