//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May 31 17:56:36 2017 by ROOT version 5.34/36
// from TChain scevtree/
//////////////////////////////////////////////////////////

#ifndef sample_chainselector_h
#define sample_chainselector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include<TEntryList.h>
// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class sample_chainselector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   
   Double_t local_counter;

   // Declaration of leaf types
   Int_t           EventHeader_runno;
   Int_t           EventHeader_eventno;
   Short_t         EventHeader_trigger;
   Int_t           EventHeader_evdate;
   Int_t           EventHeader_evtime1;
   Int_t           EventHeader_evtime2;
   Double_t        EventHeader_evcurdtime;
   Double_t        EventHeader_evabsdtime;
   Int_t           EventHeader_rtcdate;
   Int_t           EventHeader_rtctime1;
   Int_t           EventHeader_rtctime2;
   Int_t           EventHeader_gpsdate;
   Int_t           EventHeader_gpstime1;
   Int_t           EventHeader_gpstime2;
   Short_t         EventHeader_evstatus;
  Int_t           SCDATA_ndet;
  Int_t         SCDATA_detno[375];   //[ndet]
  Int_t         SCDATA_adchh[375];   //[ndet]
  Int_t         SCDATA_adchl[375];   //[ndet]
   Int_t         SCDATA_adclh[375];   //[ndet]
  Int_t         SCDATA_adcll[375];   //[ndet]
   Int_t         SCDATA_tdc[375];   //[ndet]
   Int_t         SCDATA_tdctype[375];   //[ndet]
   
  
   
  Int_t           TDCMULTHIT_nmulthit;
   Short_t         TDCMULTHIT_multhitdet[97];   //[nmulthit]
   Short_t         TDCMULTHIT_multhittdc[97];   //[nmulthit]
   Int_t           MonTDC_nmontdcmodule;
   Int_t           MonTDC_montdcmodno[1];   //[nmontdcmodule]
   Int_t           MonTDC_montdcdetno[1][32];   //[nmontdcmodule]
   Int_t           MonTDC_montdcword[1][200];   //[nmontdcmodule]
Int_t entries;
   // List of branches
   TBranch        *b_EventHeader;   //!
   TBranch        *b_SCDATA;   //!
   TBranch        *b_TDCMULTHIT;   //!
   TBranch        *b_MonTDC;   //!

   sample_chainselector(TTree * /*tree*/ =0) : fChain(0) { local_counter=0;
   }
   virtual ~sample_chainselector() {//fclose(fp); 
   }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(sample_chainselector,0);
};

#endif

#ifdef sample_chainselector_cxx
void sample_chainselector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
  
   fChain->SetMakeClass(1);
	
   fChain->SetBranchAddress("EventHeader", &EventHeader_runno,&b_EventHeader);
      fChain->SetBranchAddress("SCDATA", &SCDATA_ndet, &b_SCDATA);
      fChain->SetBranchAddress("TDCMULTHIT", &TDCMULTHIT_multhitdet, &b_TDCMULTHIT);
      fChain->SetBranchAddress("MonTDC", &MonTDC_nmontdcmodule, &b_MonTDC);
      }

Bool_t sample_chainselector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
//Info("Notify","processing file: %s",tree->GetCurrentFile()->GetName());
    TString fn(fChain->GetCurrentFile()->GetName());
   Info("Notify", "processing file: %s", fn.Data());

   return kTRUE;
}

#endif // #ifdef sample_chainselector_cxx
