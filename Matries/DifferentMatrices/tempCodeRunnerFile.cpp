n;i++){
        for(int j=1;j<=n;j++){
            cin >> x;
            Lr.RowMajor_setA(i,j,x);
        }
    }

    cout << endl;
    Lr.display(false);