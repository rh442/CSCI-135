 string filename;
    filename="playlist.txt";
   readSongs(filename);
   int count =0;
   cout<<g_number_of_songs<<endl;
    string *unique=getUniqueArtists(count);
   cout<<count<<endl;
    for(int i=0;i<g_curr_size;i++){
        cout<<unique[i]<<endl;
    }

}