class StartSetsPlayersConfig
{	
	void StartSetsPlayer(PlayerBase player,int use_set_id)
	{
		EntityAI itemCreated = NULL;
		EntityAI itemCreated1 = NULL;
		ItemBase itemCasted = NULL;
		
		switch( use_set_id ) //Раздаем лут (можно использовать значения от 1 и выше, только не 0 и не -1)
		{
			case 1: //Set with number 1 (Dony)
			{
				player.RemoveAllItems(); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку (не корректно работает, пишет краш лог)
				itemCreated = player.GetInventory().CreateInInventory("MVS_Assault_Pack_ERDL"); 	// Выдаем рюкзак
				if (itemCreated)															// Проверяем, создался ли рюкзак
				{
					SetRandomHealthItem(itemCreated);												// Выдаем рюкзаку рандомное качество
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");			// Добавляем в инвентарь созданного рюкзака яблоко
					if (itemCreated1)																// Проверяем, создалось ли яблоко в рюкзаке
					{
						SetRandomHealthItem(itemCreated1);												// Выдаем яблоку рандомное качество
					}
					itemCreated1 = NULL;															// Обнуляем значение переменной после работы с ней
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");				// Выдаем игроку бинты в рюкзак
					if (itemCreated1)																// Проверяем, создались ли бинты в рюкзаке
					{
						itemCasted = ItemBase.Cast(itemCreated1);										// Выполняем преобразование в другой класс для работы с нужной нам функцией
						itemCasted.SetQuantity(4);														// Определяем количество для созданных бинтов как 4 штуки
						SetRandomHealthItem(itemCreated);												// Выдаем бинтам рандомное качество 
					}
					itemCreated1 = NULL;															// Обнуляем значение переменной после работы с ней
				}
				itemCreated = NULL;
                itemCreated = player.GetInventory().CreateInInventory("SFE_6B47_Helmet");		
				itemCreated = NULL;                                                                                      
				itemCreated = player.GetInventory().CreateInInventory("SFE_VSRF_Pants");		// Выдаем игроку штаны
				itemCreated = NULL;
                itemCreated = player.GetInventory().CreateInInventory("MVS_GorkaJacket_Multicam_Tropic");
				itemCreated = NULL;	                                                                                        																														
				itemCreated = player.GetInventory().CreateInInventory("CombatBoots_Black");	// Выдаем игроку обувь
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("MVS_Balaclava_OD");		// Выдаем игроку Маску
				itemCreated = NULL;
                itemCreated = player.GetInventory().CreateInInventory("SFE_6b43"); 	            // Выдаем броню
				if (itemCreated)															            // Проверяем, создаласи ли броня. Если он создался, переменная itemCreated будет не пуста и проверка пройдет
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "SFE_grenpounch" );
                    itemCreated.GetInventory().CreateAttachment( "SFE_utilpounch" );                                                                       
                    itemCreated.GetInventory().CreateAttachment( "SFE_adminpounch" );                                                                             
					itemCreated.GetInventory().CreateAttachment( "SFE_magpounch" ); 		        // Выдаем карманы и крепим
					
				}
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MVS_Belt_ERDL"); 	                // Выдаем ремень
				if (itemCreated)															            // Проверяем, создался ли ремень. Если он создался, переменная itemCreated будет не пуста и проверка пройдет
				{                                                                                       
					itemCreated.GetInventory().CreateAttachment( "MVS_Sheath_Multicam_Black" );
                    itemCreated.GetInventory().CreateAttachment( "SFE_magpounch" );                                                                                     // Выдаем ножны и крепим
					itemCreated.GetInventory().CreateAttachment( "MVS_Holster_ERDL" ); 		        // Выдаем кобуру и крепим
					
				}
				itemCreated = NULL;
				//itemCasted = ItemBase.Cast(itemCreated);										// Строка не нужна, закоментирована. используется для изменения класса EntityAI в ItemBase (чтобы нужные операции были доступны)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");
                itemCreated = player.GetInventory().CreateInInventory("Battery9V");                                                                               // Выдаем игроку ножик в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("FNX45");				// Выдаем игроку FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black");		// Выдаем игроку магазины к AK74 в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black");		// Выдаем игроку магазины к AK74 в любой свободный слот в инвентаре
				itemCreated = NULL;															// Обнуляем значение переменной
				itemCreated = player.GetHumanInventory().CreateInHands("AK74_Black");				// Выдаем игроку AKM в руки
				if (itemCreated)															// Проверяем, создался ли АКМ
				{
					itemCreated.GetInventory().CreateAttachment( "KobraOptic" );                    
					itemCreated.GetInventory().CreateAttachment( "AK_PlasticBttstck_Black" ); 			// Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
					itemCreated.GetInventory().CreateAttachment( "AK_RallHndgrd_Black" );				// Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
					itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );				// Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
				}			
				break;
			}
			
			case 2: //Set with number 2  (Сет Bandit)
			{
				player.RemoveAllItems(); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку (не корректно работает, пишет краш лог)

				itemCreated = player.GetInventory().CreateInInventory("FlatCap_Grey");		// Выдаем игроку шлем
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MSFC_TacticalGogglesGreen");		// Выдаем игроку очки
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MSFC_FaceMack_Skull");		// Выдаем игроку Маску
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MSFCTraderGloves");		// Выдаем игроку перчатки
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MSFCSTALKERBanditPants");		// Выдаем игроку штаны
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("MSFCSTALKERBanditJacket");	// Выдаем игроку куртку
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("MSFCLowaZephyrBootsBlack");	// Выдаем игроку обувь
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				//itemCasted = ItemBase.Cast(itemCreated);										// Строка не нужна, закоментирована. используется для изменения класса EntityAI в ItemBase (чтобы нужные операции были доступны)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		// Выдаем игроку ножик в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("FNX45");				// Выдаем игроку FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("ChernarusMap");	// Выдаем игроку Карту в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("RageVirusCure");	// Выдаем игроку Антидот в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("TunaCan");	// Выдаем игроку консерву в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("PersonalRadio");	// Выдаем игроку рацию в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Battery9V");	// Выдаем игроку батарейку в любой свободный слот в инвентаре
				itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");				// Выдаем игроку бинты в рюкзак
					if (itemCreated1)																// Проверяем, создались ли бинты в рюкзаке
					{
						itemCasted = ItemBase.Cast(itemCreated1);										// Выполняем преобразование в другой класс для работы с нужной нам функцией
						itemCasted.SetQuantity(4);														// Определяем количество для созданных бинтов как 4 штуки
						SetRandomHealthItem(itemCreated);												// Выдаем бинтам рандомное качество 
					}
                itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				
				break;
			}
			
			case 3: //Set with number 3   (Свобода)
			{
				player.RemoveAllItems(); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку (не корректно работает, пишет краш лог)

				itemCreated = player.GetInventory().CreateInInventory("MSFCSTALKERSvobodaPants");		// Выдаем игроку штаны
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("MSFCSTALKERSvobodaJacket");	// Выдаем игроку куртку
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("MSFCLowaZephyrBootsBlack");	// Выдаем игроку обувь
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		// Выдаем игроку ножик в любой свободный слот в инвентаре
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("ChernarusMap");	// Выдаем игроку Карту в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("RageVirusCure");	// Выдаем игроку Антидот в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("TunaCan");	// Выдаем игроку консерву в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("PersonalRadio");	// Выдаем игроку рацию в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Battery9V");	// Выдаем игроку батарейку в любой свободный слот в инвентаре
				itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");				// Выдаем игроку бинты в рюкзак
					if (itemCreated1)																// Проверяем, создались ли бинты в рюкзаке
					{
						itemCasted = ItemBase.Cast(itemCreated1);										// Выполняем преобразование в другой класс для работы с нужной нам функцией
						itemCasted.SetQuantity(4);														// Определяем количество для созданных бинтов как 4 штуки
						SetRandomHealthItem(itemCreated);												// Выдаем бинтам рандомное качество 
					}
				itemCreated = player.GetInventory().CreateInInventory("Apple");		// Выдаем игроку яблоко в любой свободный слот в инвентаре
				itemCreated = NULL;
				break;
			}
			
			case 4: //Set with number 4   (Hunter)
			{
				player.RemoveAllItems(); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку (не корректно работает, пишет краш лог)
				itemCreated = player.GetInventory().CreateInInventory("HuntingBag"); 	// Выдаем рюкзак
				if (itemCreated)															// Проверяем, создался ли рюкзак
				{
					SetRandomHealthItem(itemCreated);												// Выдаем рюкзаку рандомное качество
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");			// Добавляем в инвентарь созданного рюкзака яблоко
					if (itemCreated1)																// Проверяем, создалось ли яблоко в рюкзаке
					{
						SetRandomHealthItem(itemCreated1);												// Выдаем яблоку рандомное качество
					}
					itemCreated1 = NULL;															// Обнуляем значение переменной после работы с ней
					itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");				// Выдаем игроку бинты в рюкзак
					if (itemCreated1)																// Проверяем, создались ли бинты в рюкзаке
					{
						itemCasted = ItemBase.Cast(itemCreated1);										// Выполняем преобразование в другой класс для работы с нужной нам функцией
						itemCasted.SetQuantity(4);														// Определяем количество для созданных бинтов как 4 штуки
						SetRandomHealthItem(itemCreated);												// Выдаем бинтам рандомное качество 
					}
					itemCreated1 = NULL;															// Обнуляем значение переменной после работы с ней
				}
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("HunterPants_Summer");		// Выдаем игроку штаны
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("HuntingJacket_Summer");	// Выдаем игроку куртку
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("HuntingVest");	// Выдаем игроку желет
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("CombatBoots_Black");	// Выдаем игроку обувь
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				//itemCasted = ItemBase.Cast(itemCreated);										// Строка не нужна, закоментирована. используется для изменения класса EntityAI в ItemBase (чтобы нужные операции были доступны)
	            itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		// Выдаем игроку ножик в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("FNX45");				// Выдаем игроку FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("ChernarusMap");	// Выдаем игроку Карту в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("RageVirusCure");	// Выдаем игроку Антидот в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("TunaCan");	// Выдаем игроку консерву в любой свободный слот в инвентаре
				itemCreated = NULL;															// Обнуляем значение переменной

				break;
			}
			
			case 5: //Set with number 5   (Malinka)
			{
				player.RemoveAllItems(); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку (не корректно работает, пишет краш лог)

				itemCreated = player.GetInventory().CreateInInventory("FlatCap_Grey");		// Выдаем игроку шлем
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MSFC_TacticalGogglesGreen");		// Выдаем игроку очки
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MSFCSTALKERRespirator");		// Выдаем игроку Маску
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("MSFCTraderGloves");		// Выдаем игроку перчатки
				itemCreated = NULL;
				itemCreated = player.GetInventory().CreateInInventory("Skirt_White");		// Выдаем игроку штаны
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("FS_SpecialFemale_Black");	// Выдаем игроку куртку
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("MSFCLowaZephyrBootsBlack");	// Выдаем игроку обувь
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				//itemCasted = ItemBase.Cast(itemCreated);										// Строка не нужна, закоментирована. используется для изменения класса EntityAI в ItemBase (чтобы нужные операции были доступны)
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		// Выдаем игроку ножик в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("FNX45");				// Выдаем игроку FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("ChernarusMap");	// Выдаем игроку Карту в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("RageVirusCure");	// Выдаем игроку Антидот в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("TunaCan");	// Выдаем игроку консерву в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("PersonalRadio");	// Выдаем игроку рацию в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Battery9V");	// Выдаем игроку батарейку в любой свободный слот в инвентаре
				itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");				// Выдаем игроку бинты в рюкзак
					if (itemCreated1)																// Проверяем, создались ли бинты в рюкзаке
					{
						itemCasted = ItemBase.Cast(itemCreated1);										// Выполняем преобразование в другой класс для работы с нужной нам функцией
						itemCasted.SetQuantity(4);														// Определяем количество для созданных бинтов как 4 штуки
						SetRandomHealthItem(itemCreated);												// Выдаем бинтам рандомное качество 
					}
                itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				
				break;
			}
			
			case 6: //Set with number 6   (Сет с номером 6)
			{
				break;
			}
			
			default: //Default starting spawn set (Сет поумолчанию для всех игроков, если хотите назначить - добавляйте здесь!)
			{
				player.RemoveAllItems(); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку

				itemCreated = player.GetInventory().CreateInInventory("Roadflare");	// Выдаем игроку фальшфеер
				itemCreated = NULL;	
				itemCreated = player.GetInventory().CreateInInventory("StalkerNeutralPants");		// Выдаем игроку штаны
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("Hoodie_Stalker1");	// Выдаем игроку куртку
				itemCreated = NULL;															// Обнуляем значение переменной после работы с ней
				itemCreated = player.GetInventory().CreateInInventory("HikingBoots_Brown");	// Выдаем игроку обувь
				itemCreated = NULL;	
				itemCreated = player.GetInventory().CreateInInventory("CombatKnife");		// Выдаем игроку ножик в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("FNX45");				// Выдаем игроку FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");	// Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("ChernarusMap");	// Выдаем игроку Карту в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("TunaCan");	// Выдаем игроку консерву в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("PersonalRadio");	// Выдаем игроку рацию в любой свободный слот в инвентаре
				itemCreated = player.GetInventory().CreateInInventory("Battery9V");	// Выдаем игроку батарейку в любой свободный слот в инвентаре
				itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");				// Выдаем игроку бинты в рюкзак
					if (itemCreated1)																// Проверяем, создались ли бинты в рюкзаке
					{
						itemCasted = ItemBase.Cast(itemCreated1);										// Выполняем преобразование в другой класс для работы с нужной нам функцией
						itemCasted.SetQuantity(4);														// Определяем количество для созданных бинтов как 4 штуки
						SetRandomHealthItem(itemCreated);												// Выдаем бинтам рандомное качество 
					}
					itemCreated1 = NULL;															// Обнуляем значение переменной после работы с ней
				
				player.SetPosition("12884.081055 172.868149 4463.454102")
				break;
			}
		}
	}
	
	void SetRandomHealthItem(EntityAI itemCreated)
	{
		if ( itemCreated )
		{
			private int rndHlt = Math.RandomInt(55,100);
			itemCreated.SetHealth("","",rndHlt);
		}
	}
}