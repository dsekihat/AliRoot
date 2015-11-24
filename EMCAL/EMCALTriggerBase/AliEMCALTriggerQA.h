/**
 * @file AliEMCALTriggerQA.h
 * @date Nov. 1, 2015
 * @author Salvatore Aiola <salvatore.aiola@cern.ch>, Yale University
 */
#ifndef ALIEMCALTRIGGERQA_H
#define ALIEMCALTRIGGERQA_H
/* Copyright(c) 1998-2015, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

#include <TNamed.h>
#include <TArrayI.h>

class AliEMCALTriggerPatchInfo;
class THashList;
class TObjArray;
class AliEMCALTriggerFastOR;

/**
 * @class AliEMCALTriggerQA
 * @brief Class to generate EMCal trigger QA plots
 */

class AliEMCALTriggerQA : public TNamed {
public:

  AliEMCALTriggerQA();
  AliEMCALTriggerQA(const char* name);
  virtual ~AliEMCALTriggerQA();

  void   SetDebugLevel(Int_t l)       { fDebugLevel        = l; }
  void   SetBkgPatchType(Int_t t)     { fBkgPatchType      = t; }
  void   SetTrigThr(Int_t trigType, Int_t th) { if (trigType >= 0 && trigType < 32) fTrigThr[trigType] = th; }

  Int_t  GetDebugLevel()        const { return fDebugLevel    ; }
  Int_t  GetBkgPatchType()      const { return fBkgPatchType  ; }

  void Init();
  void ProcessPatch(AliEMCALTriggerPatchInfo* patch);
  void ProcessFastor(AliEMCALTriggerFastOR* fastor);
  void EventCompleted();

  THashList* GetListOfHistograms()  { return fHistos; }

protected:

  static const Int_t      fgkMaxPatchAmp[32];           ///< Maximum patch amplitude for the histograms

  Int_t                   fTrigThr[32];                 ///< Thresholds
  Int_t                   fFastorL0Th;                  ///< FastOR L0 threshold
  Int_t                   fFastorL1Th;                  ///< FastOR L1 threshold
  Int_t                   fBkgPatchType;                ///< Background patch type

  Int_t                   fDebugLevel;                  ///< Debug level

  TArrayI                 fBkgADCAmpEMCal[2];           //!<! ADC EMCal amplitudes (0=online, 1=offline) of background patches (will be reset each event)
  Int_t                   fNBkgPatchesEMCal[2];         //!<! Number of processed background patches (will be reset each event)
  Int_t                   fMaxPatchEMCal[32][2];        //!<! EMCal max ADC amplitude (0=online, 1=offline) (will be reset each event)
  TArrayI                 fBkgADCAmpDCal[2];            //!<! ADC DCal amplitudes (0=online, 1=offline) of background patches (will be reset each event)
  Int_t                   fNBkgPatchesDCal[2];          //!<! Number of processed background patches (will be reset each event)
  Int_t                   fMaxPatchDCal[32][2];         //!<! DCal max ADC amplitude (0=online, 1=offline) (will be reset each event)

  THashList              *fHistos;                      //!<! Histograms for QA

private:
  void CreateTProfile(const char *name, const char *title, int nbins, double xmin, double xmax);
  void CreateTH1(const char *name, const char *title, int nbins, double xmin, double xmax);
  void CreateTH2(const char *name, const char *title, int nbinsx, double xmin, double xmax, int nbinsy, double ymin, double ymax);
  void CreateTH3(const char *name, const char *title, int nbinsx, double xmin, double xmax, int nbinsy, double ymin, double ymax, int nbinsz, double zmin, double zmax);
  void FillTProfile(const char *name, double x, double y, double weight = 1.);
  void FillTH1(const char *hname, double x, double weight = 1.);
  void FillTH2(const char *hname, double x, double y, double weight = 1.);
  void FillTH3(const char *hname, double x, double y, double z, double weight = 1.);

  TObject *FindObject(const char *name) const;
  virtual TObject *FindObject(const TObject *obj) const;

  AliEMCALTriggerQA(const AliEMCALTriggerQA &);
  AliEMCALTriggerQA &operator=(const AliEMCALTriggerQA &);

  /// \cond CLASSIMP
  ClassDef(AliEMCALTriggerQA, 2);
  /// \endcond
};

#endif
