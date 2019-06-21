
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

  TCutG *cutg1 = getcut("aa1","x","y");
  tree -> Draw("y:x>>(200,0,10,200,0,10)","aa1","colz");

  if (cutg1 -> IsInside(100,100))
    cout << "00000000000000000000" << endl;

  if (cutg1 -> IsInside(5,5))
    cout << "111111111111111111" << endl;
}
