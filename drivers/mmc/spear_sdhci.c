/*
 * (C) Copyright 2012
 * Vipin Kumar, ST Micoelectronics, vipin.kumar@st.com.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <malloc.h>
#include <sdhci.h>

int spear_sdhci_init(u32 regbase, u32 max_clk, u32 min_clk, u32 quirks)
{
	struct sdhci_host *host = NULL;
	host = (struct sdhci_host *)malloc(sizeof(struct sdhci_host));
	if (!host) {
		printf("sdhci host malloc fail!\n");
		return 1;
	}

	host->name = "sdhci";
	host->ioaddr = (void *)regbase;
	host->quirks = quirks;

	add_sdhci(host, max_clk, min_clk);
	return 0;
}
