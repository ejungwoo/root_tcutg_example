TCutG *getcut(TString name, TString x, TString y) {
  auto file=new TFile(TString("data/")+name.Data()+".root","read");
  auto cg=(TCutG *) file->Get(name.Data());
  cg->SetVarX(x.Data());
  cg->SetVarY(y.Data());
  return cg;
}

void draw_with_cut()
{
  auto file = new TFile("data/data.root");
  auto tree = (TTree *) file -> Get("data");

  TCutG *cutg1 = getcut("cut1","alala","boo");
  TCutG *cutg2 = getcut("cut2","alala","boo");
  auto hist = new TH2D("hist",";#it{alala};#it{boo}",200,0,10,200,0,10);
  tree -> Draw("boo:alala>>hist","!cut2&&!cut1","colz");

  if (cutg1 -> IsInside(5,5))
    cout << "(5,5) is inside the cut1" << endl;
  else
    cout << "(5,5) is outside the cut1" << endl;

  if (cutg1 -> IsInside(5,3))
    cout << "(5,3) is inside the cut1" << endl;
  else
    cout << "(5,3) is outside the cut1" << endl;
}
