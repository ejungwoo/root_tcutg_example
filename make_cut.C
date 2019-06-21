void ww(TObject *obj, TString name)
{
  TString path=TString(gSystem->Getenv("PWD"))+"/data/";
  gSystem->Exec(TString("mkdir -p ")+path);
  //name=obj->GetName();
  TString full_name=name+".root";

  full_name=name+".root";
  auto file = new TFile(path+full_name,"recreate");
  ((TCutG *) obj)->SetName(name);
  obj->Write();
  std::cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<std::endl;
  file->Close();
}

void make_cut()
{
  auto file = new TFile("data/data.root");
  auto tree = (TTree *) file -> Get("data");
  tree -> Draw("y:x>>(200,0,10,200,0,10)","","colz");
}
