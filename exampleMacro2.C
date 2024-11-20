// this is an example of how to run basic things with root

// run this with: root exampleMacro2.C
// to exit root, type .q

void exampleMacro2(){

  // TH1D* name = new TH1D("name","title",numXbins, Xmin, Xmax);
  TH1D* hist = new TH1D("hist","title",10,-5,5);
  hist->SetBinContent(1,2);
  hist->Fill(3);
  hist->Draw();

  // -------------------------------------------------------------------------------------------------------

  // TGraph* name = new TGraph;
  TGraph* myGraph = new TGraph;
  myGraph->SetMarkerStyle(20); // this tells it what you want the points to look like

  // this is a for loop to add points to the graph
  // for (int variable = initial value; how many times you loop; how to increment variable){
  // var++ means you increment by 1, you can also do var += 2, that would increase by 2 each time
  for(int i=0; i<10; i++){
    myGraph->AddPoint(i,(0.5*(i*i))+2);
  }

  // if you want to draw more than one plot at the same time, you can make another canvas (also if you want to change the size of how your graph pops up)
  // sometimes it will pop up on top of your first canvas, so you have to move it to the side to see the other one. you can also click and drag the edges to change the size by hand
  // TCanvas* name = new TCanvas("name","title", x pixels, y pixels);
  TCanvas* c2 = new TCanvas("c2","canvas 2",800,600);
  c2->cd(); // move to this canvas instead of the first one it makes automatically
  myGraph->Draw("AP"); // for a TGraph, you have to give it a draw option. "AP" means you use the marker type you specified and draw the axes

  // you can also fit your data! the fit curve will draw on top of your data points and the parameters from the fit will print out in the terminal
  gStyle->SetOptFit(1); // this tells it to make a text box on your plot with the result of your fit
  TF1* func = new TF1("func","([0]*x*x)+[1]",0,10);
  myGraph->Fit("func");

  // -------------------------------------------------------------------------------------------------------

  // now something a little more fun: errorbars!
  
  TH1D* histwErrors = new TH1D("histwErrors","histogram with errorbars",6,0,6);
  TGraphErrors* graphwErrors = new TGraphErrors;
  graphwErrors->SetTitle("graph with errorbars;x title;y title");
  graphwErrors->SetMarkerStyle(20);       graphwErrors->SetMarkerColor(2); // 2 = red
  
  for(int i=1; i<=6; i++){
    // the first bin in a histogram is bin 1, but the first point in a graph is point 0. Usually in C++, the first thing in a list is 0, histograms are just weird
    histwErrors->SetBinContent(i,i/2);
    histwErrors->SetBinError(i,sqrt(i));
    
    graphwErrors->AddPoint(i,i/2.0); // AddPoint(xcoord, ycoord)
    graphwErrors->SetPointError(i-1,0,0.5); // SetPointError(index of point, xerror, yerror)
  }
  
  // you can divide canvases too and draw 2 graphs at once.
  TCanvas* c3 = new TCanvas("c3","canvas 3",1200,400);
  c3->Divide(3,1); // (3,1) gives 3 sub-canvases (named pads) in the x-direction, 1 pad in the y direction
  
  c3->cd(1); // go to the first pad
  histwErrors->Draw();
  
  c3->cd(2); // go to the 2nd pad
  graphwErrors->Draw("AP");

  c3->cd(3); // go to the 3rd pad
  histwErrors->Draw();
  graphwErrors->Draw("PSAME"); // "SAME" draw option means it draws on top of the first plot you just drew

  // -------------------------------------------------------------------------------------------------------

  // quick intro to arrays, printing text, and C++ types

  double var1 = 5.3;
  int var2 = 123;

  cout << "my double is " << var1 << " and my integer is " << var2 << endl;

  // datatype name[number of entries] = {pt1, pt2, pt3, pt4, ....};
  double myArray[5] = {1.1, 3.8, 5.3, 7.0, 9.4};

  cout << "the first entry in my array is " << myArray[0] << endl;

  for(int j=0; j<5; j++){
    cout << "entry " << j << " is " << myArray[j] << endl;
  }

} // end of macro
