void ww(TString name)
{
  TString path=TString(gSystem->Getenv("PWD"))+"/data/";
  gSystem->Exec(TString("mkdir -p ")+path);
  TString full_name=name+".root";

  full_name=name+".root";
  auto file = new TFile(path+full_name,"recreate");
  auto cutg = (TCutG *) gPad->GetPrimitive("CUTG");
  cutg->SetName(name);
  cutg->Write();
  std::cout<<"Writing "<<cutg->GetName()<<" to "<<path+full_name<<std::endl;
  file->Close();
}

void make_cut()
{
  auto file = new TFile("data/data.root");
  auto tree = (TTree *) file -> Get("data");
  auto hist = new TH2D("hist",";#it{alala};#it{boo}",200,0,10,200,0,10);
  tree -> Draw("boo:alala>>hist","","colz");
}
