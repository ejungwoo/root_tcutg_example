void test()
{
  auto f2 = new TF2("f2","gaus((x-5))*(10-y)*(cos(2*y)+1)",0,10,0,10);
  f2 -> SetParameters(1,0,1);

  auto file = new TFile("data/data.root","recreate");
  auto tree = new TTree("data","");
  Double_t x, y;
  tree -> Branch("x",&x);
  tree -> Branch("y",&y);

  for (auto i=0; i<100000; ++i) {
    f2 -> GetRandom2(x,y);
    tree -> Fill();
  }

  tree -> Write();
}
