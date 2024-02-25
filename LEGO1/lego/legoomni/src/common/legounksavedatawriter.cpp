#include "legounksavedatawriter.h"

#include "legogamestate.h"
#include "legoomni.h"
#include "roi/legoroi.h"

DECOMP_SIZE_ASSERT(LegoUnkSaveDataWriter, 0x08)
DECOMP_SIZE_ASSERT(LegoSaveDataEntry3, 0x108)

// GLOBAL: LEGO1 0x100f80c0
LegoSaveDataEntry3 g_saveDataInit[66]; // TODO: add data

// GLOBAL: LEGO1 0x100fc4e4
char* LegoUnkSaveDataWriter::g_customizeAnimFile = NULL;

// GLOBAL: LEGO1 0x10104f20
LegoSaveDataEntry3 g_saveData3[66];

// FUNCTION: LEGO1 0x10082a20
LegoUnkSaveDataWriter::LegoUnkSaveDataWriter()
{
	m_map = new LegoUnkSaveDataMap();
	InitSaveData();

	m_customizeAnimFile = new CustomizeAnimFileVariable("CUSTOMIZE_ANIM_FILE");
	VariableTable()->SetVariable(m_customizeAnimFile);
}

// FUNCTION: LEGO1 0x10083270
void LegoUnkSaveDataWriter::InitSaveData()
{
	for (MxS32 i = 0; i < 66; i++) {
		g_saveData3[i] = g_saveDataInit[i];
	}
}

// STUB: LEGO1 0x100832a0
void LegoUnkSaveDataWriter::FUN_100832a0()
{
	// TODO
}

// FUNCTION: LEGO1 0x10083310
MxResult LegoUnkSaveDataWriter::WriteSaveData3(LegoStorage* p_stream)
{
	MxResult result = FAILURE;

	// This should probably be a for loop but I can't figure out how to
	// make it match as a for loop.
	LegoSaveDataEntry3* entry = g_saveData3;
	const LegoSaveDataEntry3* end = &g_saveData3[66];

	while (TRUE) {
		if (p_stream->Write(&entry->m_savePart1, 4) != SUCCESS) {
			break;
		}
		if (p_stream->Write(&entry->m_savePart2, 4) != SUCCESS) {
			break;
		}
		if (p_stream->Write(&entry->m_savePart3, 1) != SUCCESS) {
			break;
		}
		if (p_stream->Write(&entry->m_currentFrame, 1) != SUCCESS) {
			break;
		}
		if (p_stream->Write(&entry->m_savePart5, 1) != SUCCESS) {
			break;
		}
		if (p_stream->Write(&entry->m_savePart6, 1) != SUCCESS) {
			break;
		}
		if (p_stream->Write(&entry->m_savePart7, 1) != SUCCESS) {
			break;
		}
		if (p_stream->Write(&entry->m_savePart8, 1) != SUCCESS) {
			break;
		}
		if (p_stream->Write(&entry->m_savePart9, 1) != SUCCESS) {
			break;
		}
		if (p_stream->Write(&entry->m_savePart10, 1) != SUCCESS) {
			break;
		}
		if (++entry >= end) {
			result = SUCCESS;
			break;
		}
	}
	return result;
}

// STUB: LEGO1 0x10083500
LegoROI* LegoUnkSaveDataWriter::FUN_10083500(char* p_key, MxBool p_option)
{
	// TODO
	// involves an STL map with a _Nil node at 0x100fc508
	return NULL;
}

// STUB: LEGO1 0x10083db0
void LegoUnkSaveDataWriter::FUN_10083db0(LegoROI* p_roi)
{
	// TODO
}

// STUB: LEGO1 0x10083f10
void LegoUnkSaveDataWriter::FUN_10083f10(LegoROI* p_roi)
{
	// TODO
}

// FUNCTION: LEGO1 0x100851a0
void LegoUnkSaveDataWriter::SetCustomizeAnimFile(const char* p_value)
{
	if (g_customizeAnimFile != NULL) {
		delete[] g_customizeAnimFile;
	}

	if (p_value != NULL) {
		g_customizeAnimFile = new char[strlen(p_value) + 1];

		if (g_customizeAnimFile != NULL) {
			strcpy(g_customizeAnimFile, p_value);
		}
	}
	else {
		g_customizeAnimFile = NULL;
	}
}

// STUB: LEGO1 0x10085210
LegoROI* LegoUnkSaveDataWriter::FUN_10085210(LegoChar*, LegoChar*, undefined)
{
	return NULL;
}

// FUNCTION: LEGO1 0x10085a80
LegoROI* LegoUnkSaveDataWriter::FUN_10085a80(LegoChar* p_und1, LegoChar* p_und2, undefined p_und3)
{
	return FUN_10085210(p_und1, p_und2, p_und3);
}
