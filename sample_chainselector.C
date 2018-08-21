#define sample_chainselector_cxx
// The class definition in sample_chainselector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("sample_chainselector.C")
// Root > T->Process("sample_chainselector.C","some options")
// Root > T->Process("sample_chainselector.C+")
//

#include "sample_chainselector.h"
#include <TH2.h>
#include <TStyle.h>
#include<TLeaf.h>
#include<TTree.h>
#include<TTreePlayer.h>


void sample_chainselector::Begin(TTree * tree)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
//Init(tree);
   TString option = GetOption();
     printf("Begin executed\n");

}

void sample_chainselector::SlaveBegin(TTree * tree)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).
   
   

   TString option = GetOption();
  
}

Bool_t sample_chainselector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either sample_chainselector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
	local_counter++;
	
	
printf("\n entryno:%lld \n ",entry);
b_EventHeader->GetEntry(entry);
printf("eventno %lf:\t \n",b_EventHeader->GetLeaf("eventno")->GetValue());


printf("runno %lf:\t \n",b_EventHeader->GetLeaf("runno")->GetValue());
printf("Multi %lf: \t \n",b_EventHeader->GetLeaf("eventno")->GetValue()*b_EventHeader->GetLeaf("runno")->GetValue());
	printf("Process executed\n");
   return kTRUE;
}

void sample_chainselector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

	//	fprintf(fp,"\nTotal events by SlaveTerminate = %lf",local_counter);
		printf("\nTotal events by SlaveTerminate = %lf",local_counter);
		printf("SlaveTerminate executed\n");
				
		

}

void sample_chainselector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   
	printf("\nTerminate executed\n");

}

/*

b_SCDATA->GetEntry(entry);
printf("ndet %lf:\t \n",b_SCDATA->GetLeaf("ndet")->GetValue());


*/
