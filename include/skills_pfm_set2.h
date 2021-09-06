
void copy_menpai3()
{
	switch(u_menpai)
	{
	case "mj":												//设定明教武功
			set("family/family_name","明教");
			set_skill("piaoyi-shenfa",500);						//明教轻功：飘翼身法
			map_skill("dodge", "piaoyi-shenfa");
			set_skill("qiankun-danuoyi",500);
			u_f_pfm=u_f_pfm + ({(: perform_action, "parry.hua" :)});	
			u_f_pfm=u_f_pfm + ({(: perform_action, "parry.xu" :)});	
			//u_f_pfm=u_f_pfm + ({(: perform_action, "parry.yin" :)});
			switch(in_level)
			{
				case 0:
					set_skill("shenghuo-shengong",500);									//明教低级内功：圣火神功
					map_skill("force","shenghuo-shengong");

					switch(random(2))
					{
						case 0:
							set_skill("yingzhua-shou",500);                             //明教低级空手：鹰爪擒拿手
							map_skill("hand","yingzhua-shou");
							nw_parry="qiankun-danuoyi";									//设定乾坤大挪移为招架
							prepare_skill("hand", "yingzhua-shou");
							set("f_skill","yingzhua-shou");
						break;
						case 1:
							set_skill("hanbing-mianzhang",500);                             //明教低级空手：寒冰绵掌
							map_skill("strike","hanbing-mianzhang");
							nw_parry="hanbing-mianzhang";									//pfm xixue 要求parry 为hanbing-mianzhang
							prepare_skill("strike", "hanbing-mianzhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.xixue" :)});		//寒冰绵掌pfm:吸血
							set("f_skill","hanbing-mianzhang");
						break;

					}
					switch(random(2))
					{
						case 0:
							set_skill("liehuo-jian",500);                             		  //明教低级武器：烈火剑
							map_skill("sword","liehuo-jian");
							w_parry="qiankun-danuoyi";									      //设定乾坤大挪移为招架
							u_weapon="sword";
							set("f_w_skill","liehuo-jian");
						break;
						case 1:
							set_skill("lieyan-dao",500);                              		 //明教低级武器：烈焰刀
							map_skill("blade","lieyan-dao");
							w_parry="qiankun-danuoyi";										 //设定乾坤大挪移为招架
							u_w_pfm = u_w_pfm + ({(: perform_action, "blade.shenghuo" :)});		 //烈焰刀pfm:圣火
							u_weapon="blade";
							set("f_w_skill","lieyan-dao");
						break;
					}
				break;
				case 1:
					set_skill("jiuyang-shengong",500);									//明教高级内功：九阳神功
					set_skill("shenghuo-shengong",500);									//明教低级内功：圣火神功
					map_skill("force","jiuyang-shengong");
					u_f_pfm=u_f_pfm + ({(: exert_function, "jiuyang" :)});	 //powerup	
					if(!in_weapon)
					switch(random(1))													//明教圣火令法可以为cuff，但强制要求tisha需要cuff 为shenghuo-lingfa 则不好
					{																	//至少限制了空手后明教的主打武功七伤拳。 campsun 注	
						case 0:
							set_skill("qishang-quan",500);								//明教高级空手：七伤拳		
							map_skill("cuff","qishang-quan");
							nw_parry="qiankun-danuoyi";										//设定乾坤大挪移为招架
							prepare_skill("cuff","qishang-quan");
							u_pfm = u_pfm + ({(: perform_action, "cuff.qishang" :)});     //七伤拳pfm：七伤
							u_pfm = u_pfm + ({(: perform_action, "cuff.duanhun" :)});     //七伤拳pfm：断魂
							set("f_skill","qishang-quan");
						break;
					}
					else
					switch(random(1))
					{
						case 0:
							set_skill("shenghuo-lingfa",500);										//明教高级兵器：圣火令法
							map_skill("dagger","shenghuo-lingfa");									//设定乾坤大挪移为招架
							if(in_weapon)
							{
								pmap = query_skill_prepare();
								if (sizeof(pmap))
								{
									skill = keys(pmap);
									foreach (string item in skill)
									prepare_skill(item);
								}																		//防止hubei
								
								map_skill("cuff","shenghuo-lingfa");
								prepare_skill("cuff","shenghuo-lingfa");
								nw_parry="qiankun-danuoyi";
								set("f_skill","shenghuo-lingfa");
							}
							w_parry="qiankun-danuoyi";
							u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.duo" :)});        	//圣火令法pfm：夺
							u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.ji" :)});			//击
							u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.tisha" :)});			//踢沙	
							u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.xinmo" :)});			//心魔
							//u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.tougu" :)});
							//u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.yinfeng" :)});
							u_weapon="dagger";
							set("f_w_skill","shenghuo-lingfa");
						break;
					}					
				break;	
				}
			break;//end case mj	

		case "thd":												//设定桃花岛武功
			set("family/family_name","桃花岛");
			set_skill("bihai-chaosheng",500);					//桃花岛内功：碧海潮生功			
			set_skill("suibo-zhuliu",500);						//桃花岛轻功：随波逐流 
			set_skill("qimen-bagua",200);
			set("thd/perform",31);
			map_skill("force", "bihai-chaosheng");
			map_skill("dodge", "suibo-zhuliu");
//			u_f_pfm=u_f_pfm + ({(: exert_function, "play" :)});   //碧海潮生功pfm：吹箫
			u_f_pfm=u_f_pfm + ({(: exert_function, "maze" :)});     //布阵
			u_ub_pfm=u_ub_pfm + ({(: exert_function, "qimen" :)});     //奇门五行
			u_f_pfm=u_f_pfm + ({(: perform_action, "dodge.wuzhuan" :)});			//随波逐流pfm:五转

			switch(in_level)
			{
				case 0:
					switch(random(3))
					{
						case 0:
							set_skill("lanhua-shou",500);                             //桃花岛低级空手：兰花拂穴手
							map_skill("hand","lanhua-shou");
							nw_parry="lanhua-shou";
							prepare_skill("hand", "lanhua-shou");
							u_pfm=u_pfm + ({(: perform_action, "hand.fuxue" :)});        //兰花拂穴手pfm：抚穴
							set("f_skill","lanhua-shou");
						break;
						case 1:
							set_skill("luoying-zhang",500);                             //桃花岛低级空手：落英神剑掌
							map_skill("strike","luoying-zhang");
							nw_parry="luoying-zhang";
							prepare_skill("strike", "luoying-zhang");
							u_pfm=u_pfm + ({(: perform_action, "strike.fugu" :)});        //落英神剑掌pfm：抚骨
							u_pfm=u_pfm + ({(: perform_action, "strike.pikong" :)});        //落英神剑掌pfm：劈空
							u_pfm=u_pfm + ({(: perform_action, "strike.bading" :)});        //落英神剑掌pfm：拔钉
							set("f_skill","luoying-zhang");

						break;
						case 2:
							set_skill("xuanfeng-tui",500);                             //桃花岛低级空手：旋风扫叶腿
							set_skill("luoying-zhang",500);                             //pfm xuanfeng 的要求
							map_skill("strike","luoying-zhang");
							map_skill("leg","xuanfeng-tui");
							nw_parry="xuanfeng-tui";
							prepare_skill("leg", "xuanfeng-tui");
							u_pfm=u_pfm + ({(: perform_action, "leg.kuangfeng" :)});        //旋风扫叶腿pfm：狂风
							set("f_skill","xuanfeng-tui");
						break;
					}
					switch(random(1))															
					{
						case 0:
							set_skill("tanzhi-shentong",500);								//桃花岛高级空手：弹指神通	
							map_skill("finger","tanzhi-shentong");
							map_skill("throwing","tanzhi-shentong");						//弹指神通做暗器
							w_parry="tanzhi-shentong";
							prepare_skill("finger","tanzhi-shentong");
							u_w_pfm = u_w_pfm + ({(: perform_action, "finger.shentong" :)});     //弹指神通pfm：神通
							u_w_pfm = u_w_pfm + ({(: perform_action, "finger.tan" :)});     //弹指神通pfm：弹
							u_w_pfm = u_w_pfm + ({(: perform_action, "finger.huayu" :)}); 
							switch(random(3))
							{
								case 0:
									set_skill("xuanfeng-tui",500);
									map_skill("leg","xuanfeng-tui");
									set("env/xinghe","xuanfeng-tui");
								break;
								case 1:
									set_skill("lanhua-shou",500);                             
									map_skill("hand","lanhua-shou");
									set("env/xinghe","lanhua-shou");
								break;
								case 2:
									set_skill("luoying-zhang",500); 
									map_skill("strike","luoying-zhang");
									set("env/xinghe","luoying-zhang");
								break;
							
							}
							u_w_pfm = u_w_pfm + ({(: perform_action, "finger.xinghe" :)});     //弹指神通pfm：星河千帆舞
							set("f_w_skill","tanzhi-shentong");
							u_weapon="feihuangshi";
						break;
					}
																						
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("tanzhi-shentong",500);								//桃花岛高级空手：弹指神通	
							map_skill("finger","tanzhi-shentong");
							map_skill("throwing","tanzhi-shentong");						//弹指神通做暗器
							nw_parry="tanzhi-shentong";
							prepare_skill("finger","tanzhi-shentong");
//							u_pfm = u_pfm + ({(: perform_action, "finger.qiankun" :)});     //弹指神通pfm：乾坤一指
							u_pfm = u_pfm + ({(: perform_action, "finger.tan" :)});     //弹指神通pfm：弹
							switch(random(3))
							{
								case 0:
									set_skill("xuanfeng-tui",500);
									map_skill("leg","xuanfeng-tui");
									set("env/xinghe","xuanfeng-tui");
								break;
								case 1:
									set_skill("lanhua-shou",500);                             
									map_skill("hand","lanhua-shou");
									set("env/xinghe","lanhua-shou");
								break;
								case 2:
									set_skill("luoying-zhang",500); 
									map_skill("strike","luoying-zhang");
									set("env/xinghe","luoying-zhang");
								break;
							
							}
							u_pfm = u_pfm + ({(: perform_action, "finger.xinghe" :)});     //弹指神通pfm：星河千帆舞
							set("f_skill","tanzhi-shentong");

						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("yuxiao-jian",500);										//桃花岛高级兵器：玉箫剑法
							set_skill("tanzhi-shentong",500);
							map_skill("finger","tanzhi-shentong");
							set_skill("xuanfeng-tui",500);
							map_skill("leg","xuanfeng-tui");
							set_skill("luoying-zhang",500);
							map_skill("strike","luoying-zhang");
							set_skill("lanhua-shou",500); 
							map_skill("hand","lanhua-shou");
							map_skill("sword","yuxiao-jian");
							w_parry="yuxiao-jian";
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.feiying" :)});        	//玉箫剑法pfm：飞影
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.qimen" :)});			//奇门
							u_weapon="xiao";													//pfm feiying 需要装备箫为武器		
							set("f_w_skill","yuxiao-jian");
						break;
					}					
				break;	
				}
			break;//end case thd
			
		case "tls":																		//tls kungfu set							
			set("family/family_name","天龙寺");
			set("family/master_name","一灯大师");
			set_skill("qiantian-yiyang",500);											//天龙寺低级内功：乾天一阳
			set_skill("tianlong-xiang",500);											//天龙寺轻功：天龙翔
			set_skill("buddhism",200);
			set("class","bonze");		
			map_skill("force", "qiantian-yiyang");
			map_skill("dodge", "tianlong-xiang");
			u_ub_pfm=u_ub_pfm + ({(: exert_function, "xinjing" :)}); 
			u_ub_pfm=u_ub_pfm + ({(: exert_function, "jujing" :)});  
			switch(in_level)
			{
				case 0:
					switch(random(3))
					{
						case 0:
							set_skill("qingyan-zhang",500);                             		//天龙寺低级空手：五罗轻烟掌
							map_skill("strike","qingyan-zhang");
							nw_parry="qingyan-zhang";
							prepare_skill("strike", "qingyan-zhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.piaoying" :)});		//飘影掌
							set("f_skill","qingyan-zhang");
						break;
						case 1:
							set_skill("duanjia-quan",500);                             			//天龙寺低级空手：段家拳法
							map_skill("cuff","duanjia-quan");
							nw_parry="duanjia-quan";
							prepare_skill("cuff", "duanjia-quan");
							set("f_skill","duanjia-quan");
						break;
						case 2:
							set_skill("yiyang-zhi",500);										//天龙寺低级空手：一阳指
							map_skill("finger","yiyang-zhi");
							nw_parry="yiyang-zhi";
							prepare_skill("finger","yiyang-zhi");
							u_pfm = u_pfm + ({(: perform_action, "finger.sandie" :)}); 			//一阳指pfm：阳关三叠
							u_pfm = u_pfm + ({(: perform_action, "finger.yizhisanmai" :)}); 	//一指三脉
							u_pfm = u_pfm + ({(: perform_action, "staff.rou" :)});
							set("f_skill","yiyang-zhi");
						break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("duanjia-jianfa",500);                               		//天龙寺低级兵器：段家剑法
							map_skill("sword","duanjia-jianfa");
							if(in_weapon)
							{
								pmap = query_skill_prepare();
								if (sizeof(pmap))
								{
									skill = keys(pmap);
									foreach (string item in skill)
									prepare_skill(item);
								}
								set_skill("qingyan-zhang",500);                             
								map_skill("strike","qingyan-zhang");
								prepare_skill("strike", "qingyan-zhang");
								set("f_skill","qingyan-zhang");
							}
							w_parry="qingyan-zhang";
							u_w_pfm=u_w_pfm + ({(: perform_action, "sword.fenglei" :)});          	//段家剑法pfm：风雷四击
							u_weapon="sword";
							set("f_w_skill","duanjia-jianfa");						
						break;
					}
				break;
				case 1:
					set_skill("kurong-changong",500);											//天龙寺高级内功：枯荣禅功
					map_skill("force","kurong-changong");
					switch(random(2))
					{
						case 0:										
							map_skill("strike","kurong-changong");								//天龙寺高级空手：枯荣禅功
							nw_parry="kurong-changong";
							prepare_skill("strike","kurong-changong");
							u_pfm = u_pfm + ({(: exert_function, "rong" :)}); 					//枯荣禅功pfm：荣
							u_pfm = u_pfm + ({(: perform_action, "strike.jiuchong" :)});		//九重天
							u_pfm = u_pfm + ({(: exert_function, "ku" :)});
							set("f_skill","kurong-changong");     
						break;
						case 1:
							u_liumai=str_liumai[random(sizeof(str_liumai))];					//天龙寺高级空手：六脉神剑
							set("env/liumai",u_liumai);
							set("liumai-shenjian/"+u_liumai,1);
							set_skill("yiyang-zhi",500);
							set_skill("liumai-shenjian",500);										
							map_skill("finger","yiyang-zhi");
							nw_parry="yiyang-zhi";
							prepare_skill("finger","yiyang-zhi");
                                                   u_pfm = u_pfm + ({(: perform_action, "finger.ciqu" :)}); 
							u_pfm = u_pfm + ({(: perform_action, "finger.yizhisanmai" :)});
							u_w_pfm = u_w_pfm + ({(: perform_action, "staff.rou" :)}); 
//							u_pfm = u_pfm + ({(: perform_action, "qianlong" :)});     
							set("f_skill","liumai-shenjian");
						break;
						
					}
					switch(random(3))
					{
						case 0:
							set_skill("cihang-bian",500);										//天龙寺高级兵器：慈航鞭
							set("shen",530000);												//need for pfm	
							map_skill("whip","cihang-bian");
							w_parry="cihang-bian";
							u_w_pfm = u_w_pfm + ({(: perform_action, "whip.cibei" :)});        		//慈航鞭pfm：慈悲字诀
							u_weapon="whip";
							set("f_w_skill","cihang-bian");
						break;
						case 1:
							set_skill("pangen-fu",500);											//天龙寺高级兵器：盘根错结斧
							map_skill("axe","pangen-fu");
							w_parry="pangen-fu";
							u_w_pfm = u_w_pfm + ({(: perform_action, "axe.jingtian" :)});        	//盘根错结斧pfm：惊天断云斧
							u_weapon="axe";
							set("f_w_skill","pangen-fu");
						break;
						case 2:
							map_skill("force", "qiantian-yiyang");
							set_skill("yiyang-zhi",500);											//天龙寺高级兵器：一阳指
							map_skill("staff","yiyang-zhi");
							map_skill("finger","yiyang-zhi");
							prepare_skill("finger","yiyang-zhi");
							w_parry="yiyang-zhi";
							u_w_pfm = u_w_pfm + ({(: perform_action, "staff.yin" :)});
							u_weapon="staff";
							set("f_w_skill","yiyang-zhi");						
						
						break;
					}					
				break;	
				}
			break;//end case tls		

		case "sl":		
			set("family/family_name","少林派");
			set_skill("yijin-jing",500);													//少林内功：易筋经
			set_skill("shaolin-shenfa",500);												//少林轻功：少林身法
			set_skill("buddhism",200);														//少林杂项：禅宗心法
			map_skill("force", "yijin-jing");
			map_skill("dodge", "shaolin-shenfa");
			u_f_pfm=u_f_pfm + ({(: exert_function, "jingang" :)});   							//易筋经pfm：金刚不坏体神功
			switch(in_level)
			{
				case 0:
					switch(random(8))
					{
						case 0:
							set_skill("fengyun-shou",500);                             		//少林低级空手：风云手
							map_skill("hand","fengyun-shou");
							nw_parry="fengyun-shou";
							prepare_skill("hand", "fengyun-shou");
							set("f_skill","fengyun-shou");
						break;
						case 1:
							set_skill("yingzhua-gong",500);                             	//少林低级空手：鹰爪功
							map_skill("claw","yingzhua-gong");
							nw_parry="yingzhua-gong";
							prepare_skill("claw", "yingzhua-gong");
							set("f_skill","yingzhua-gong");
						break;
						case 2:
							set_skill("mohe-zhi",500);                             			//少林低级空手：摩诃指
							map_skill("finger","mohe-zhi");
							nw_parry="mohe-zhi";
							prepare_skill("finger", "mohe-zhi");
							set("f_skill","mohe-zhi");
						break;
						case 3:
							set_skill("jimie-zhua",500);                             		//少林低级空手：寂灭爪
							map_skill("claw","jimie-zhua");
							nw_parry="jimie-zhua";
							prepare_skill("claw", "jimie-zhua");
							set("f_skill","jimie-zhua");
						break;
						case 4:
							set_skill("shaolin-tantui",500);                             	//少林低级空手：少林弹腿
							map_skill("leg","shaolin-tantui");
							nw_parry="shaolin-tantui";
							prepare_skill("leg", "shaolin-tantui");
							set("f_skill","shaolin-tantui");
						break;
						case 5:
							set_skill("weituo-zhang",500);                             		//少林低级空手：韦陀掌
							map_skill("strike","weituo-zhang");
							nw_parry="weituo-zhang";
							prepare_skill("strike", "weituo-zhang");
							set("f_skill","weituo-zhang");
						break;
						case 6:
							set_skill("luohan-quan",500);                             		//少林低级空手：罗汉拳
							map_skill("cuff","luohan-quan");
							nw_parry="luohan-quan";
							prepare_skill("cuff", "luohan-quan");
							set("f_skill","luohan-quan");
						break;
						case 7:
							set_skill("sanhua-zhang",500);     								//少林低级空手：散花掌
							set_skill("nianhua-zhi",500);                             		//少林低级空手：拈花指
                      		map_skill("strike","sanhua-zhang");
    						map_skill("finger","nianhua-zhi");
							prepare_skill("strike", "sanhua-zhang");
							prepare_skill("finger", "nianhua-zhi");
							nw_parry="nianhua-zhi";
							u_pfm = u_pfm + ({(: perform_action, "strike.sanhua" :)});
							u_pfm = u_pfm + ({(: perform_action, "finger.fuxue" :)});    
							set("f_skill","sanhua-zhang");									//散花掌pfm：四季散花
							set("f_skill2","nianhua-zhi");									//拈花指pfm：拈花拂穴
							
						break;

					}
					switch(random(8))
					{
						case 0:
							set_skill("xiuluo-dao",500);                               		//少林低级兵器：修罗刀 
							map_skill("blade","xiuluo-dao");
							w_parry="xiuluo-dao";
							u_weapon="blade";
							set("f_w_skill","xiuluo-dao");
						break;
						case 1:
							set_skill("pudu-zhang",500);                               		//少林低级兵器：普渡杖
							map_skill("staff","pudu-zhang");
							w_parry="pudu-zhang";
							u_weapon="staff";
							set("f_w_skill","pudu-zhang");
						break;
						case 2:
							set_skill("zui-gun",500);                               		//少林低级兵器：少林醉棍
							map_skill("club","zui-gun");
							apply_condition("drunk",300);
							w_parry="zui-gun";
							u_weapon="club";
							u_w_pfm = u_w_pfm + ({(: perform_action, "club.zuijiu" :)}); 		//少林醉棍pfm：八仙醉打
							set("f_w_skill","zui-gun");   
						break;
						case 3:
							set_skill("damo-jian",500);                               		//少林低级兵器：达摩剑
							map_skill("sword","damo-jian");
							w_parry="damo-jian";
							u_weapon="sword";
							set("f_w_skill","damo-jian");
						break;
						case 4:
							set_skill("weituo-gun",500);                               		//少林低级兵器：韦陀棍
							map_skill("club","weituo-gun");
							w_parry="weituo-gun";
							u_weapon="club";
							set("f_w_skill","weituo-gun");
						break;
						case 5:
							set_skill("cibei-dao",500);                               		//少林低级兵器：慈悲刀
							map_skill("blade","cibei-dao");
							w_parry="cibei-dao";
							u_weapon="blade";
							set("f_w_skill","cibei-dao");
						break;
						case 6:
							set_skill("fumo-jian",500);                               		//少林低级兵器：伏魔剑	
							map_skill("sword","fumo-jian");
							w_parry="fumo-jian";
							u_weapon="sword";
							set("f_w_skill","fumo-jian");
						break;
						case 7:
							set_skill("wuchang-zhang",500);                               	//少林低级兵器：无常杖
							map_skill("staff","wuchang-zhang");
							w_parry="wuchang-zhang";
							u_weapon="staff";
							set("f_w_skill","wuchang-zhang");
						break;
					}
				break;
				case 1:
					switch(random(4))
					{
						case 0:
							set_skill("yizhi-chan",500);										//少林高级空手：一指禅
							set_skill("longzhua-gong",500);										//少林高级空手：龙爪功
							map_skill("claw","longzhua-gong");
							map_skill("finger","yizhi-chan");
							prepare_skill("claw","longzhua-gong");
							prepare_skill("finger","yizhi-chan");
							nw_parry="yizhi-chan";
							u_pfm = u_pfm + ({(: perform_action, "finger.wofo" :)});    		//一指禅pfm：皈依我佛
							u_pfm = u_pfm + ({(: perform_action, "finger.qiankun" :)}); 		//一指乾坤
							u_pfm = u_pfm + ({(: perform_action, "claw.canyun" :)}); 			//龙爪功pfm：风卷残云
							set("f_skill","yizhi-chan");
							set("f_skill2","longzhua-gong");   
   						break;
						case 1:
							set_skill("ruying-suixingtui",500);									//少林高级空手：如影随形腿
							set_skill("qianye-shou",500);										//少林高级空手：如来千叶手
							map_skill("leg","ruying-suixingtui");
							map_skill("hand","qianye-shou");
							prepare_skill("leg","ruying-suixingtui");
							prepare_skill("hand","qianye-shou");
							nw_parry="qianye-shou";
							u_pfm = u_pfm + ({(: perform_action, "hand.qianshou" :)});    		//如来千叶手pfm：千手如来
							u_pfm = u_pfm + ({(: perform_action, "leg.ruying" :)});    			//如影随形腿pfm：如影随形
							set("f_skill","ruying-suixingtui");
							set("f_skill2","qianye-shou");
						break;
						case 2:
							set_skill("jingang-quan",500);										//少林高级空手：大金刚拳
							map_skill("cuff","jingang-quan");
							set_skill("banruo-zhang",500);										//少林高级空手：般若掌
							map_skill("strike","banruo-zhang");
							nw_parry="banruo-zhang";
							prepare_skill("strike","banruo-zhang");
							prepare_skill("cuff","jingang-quan");
							u_pfm = u_pfm + ({(: perform_action, "strike.chaodu" :)}); 			//般若掌pfm：超度连环诀
							if(random(5)==1)
							u_pfm = u_pfm + ({(: perform_action, "strike.yipai" :)});   		//一拍两散
							u_pfm = u_pfm + ({(: perform_action, "cuff.fumo" :)});    			//大金刚拳pfm：金刚伏魔
							set("f_skill","jingang-quan");
							set("f_skill2","banruo-zhang");
 						break;
 						case 3:
							set_skill("wuxiang-zhi",500);										//少林高级空手：无相劫指
							map_skill("finger","wuxiang-zhi");
							prepare_skill("finger","wuxiang-zhi");
							nw_parry="wuxiang-zhi";
 							u_pfm = u_pfm + ({(: perform_action, "finger.qiankun" :)}); 		//无相劫指pfm：袖里乾坤
							set("f_skill","wuxiang-zhi");
   						break;
					}
					switch(random(3))
					{
						case 0:
							set_skill("riyue-bian",500);										//少林高级兵器：日月鞭法
							map_skill("whip","riyue-bian");
							w_parry="riyue-bian";
							u_w_pfm = u_w_pfm + ({(: perform_action, "whip.fumoquan" :)});        	//日月鞭法pfm：金刚伏魔圈
							u_w_pfm = u_w_pfm + ({(: perform_action, "whip.chanrao" :)});        	//天缠地绕 
							u_weapon="whip";
							set("f_w_skill","riyue-bian");
						break;
						case 1:
							set_skill("ranmu-daofa",500);										//少林高级兵器：燃木刀法
							map_skill("blade","ranmu-daofa");
							w_parry="ranmu-daofa";
//							u_w_pfm = u_w_pfm + ({(: perform_action, "blade.fentian" :)});			//燃木刀法pfm：举火焚天
							u_w_pfm = u_w_pfm + ({(: perform_action, "blade.fenwo" :)});        	//焚我
							u_w_pfm = u_w_pfm + ({(: perform_action, "blade.fenxin" :)});        	//焚心 需要木刀才能发
							u_weapon="blade";
							set("f_w_skill","ranmu-daofa");
						break;
						case 2:
							set_skill("weituo-chu",500);										//少林高级兵器：韦陀杵
							map_skill("club","weituo-chu");
							w_parry="weituo-chu";
							u_w_pfm = u_w_pfm + ({(: perform_action, "club.leidong" :)});			//韦陀杵pfm：雷动九天
							u_w_pfm = u_w_pfm + ({(: perform_action, "club.chaodu" :)});        	//超度极乐 
							u_weapon="club";
							set("f_w_skill","weituo-chu");
						break;
					}					
				break;	
				}
			break;//end case sl	
		case "kl":
			set("family/family_name","昆仑派");
			set_skill("xuantian-wuji",500);													//昆仑内功：玄天无极功
			set_skill("taxue-wuhen",500);													//昆仑轻功：踏雪无痕
			set_skill("art",200);															//昆仑杂项：琴棋书画	
			map_skill("force", "xuantian-wuji");
			map_skill("dodge", "taxue-wuhen");
			u_f_pfm=u_f_pfm + ({(: exert_function, "riyue" :)});   							
			u_f_pfm=u_f_pfm + ({(: exert_function, "taxue" :)});     							
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("chuanyun-tui",500);                            		//昆仑低级空手：穿云腿
							map_skill("leg","chuanyun-tui");
							nw_parry="chuanyun-tui";
							prepare_skill("leg", "chuanyun-tui");
							u_pfm = u_pfm + ({(: perform_action, "leg.chuanyun" :)});
							set("f_skill","chuanyun-tui");
						break;
						case 1:
							set_skill("zhentian-quan",500);                            		//昆仑低级空手：震天拳
							map_skill("cuff","zhentian-quan");
							nw_parry="zhentian-quan";
							prepare_skill("cuff", "zhentian-quan");
							u_pfm = u_pfm + ({(: perform_action, "cuff.kaishan" :)});
							set("f_skill","zhentian-quan");
						break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("xunlei-jian",500);                              		//昆仑低级兵器：迅雷剑
							map_skill("sword","xunlei-jian");
							w_parry="xunlei-jian";
							u_weapon="sword";
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.xunlei" :)});
							set("f_w_skill","xunlei-jian");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("kunlun-zhang",500);									 //昆仑高级空手：昆仑掌法
							map_skill("strike","kunlun-zhang");
							nw_parry="kunlun-zhang";
							prepare_skill("strike","kunlun-zhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.diezhang" :)});     //昆仑掌法pfm：昆山叠掌
							u_pfm = u_pfm + ({(: perform_action, "strike.xuebeng" :)});
							set("f_skill","kunlun-zhang");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("liangyi-jian",500);									//昆仑高级兵器：两仪剑法	
							map_skill("sword","liangyi-jian");
							w_parry="liangyi-jian";
//							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.hebi" :)});        	//两仪剑法pfm：双剑合壁 
//							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.hundun" :)});
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.xunlei" :)});
							u_weapon="sword";
							set("f_w_skill","liangyi-jian");
						break;
					}					
				break;	
				}
			break;//end case kl	
		case "9y":
			set("family/family_name","九阴真经传人");
			set_skill("jiuyin-zhengong",500);												//九阴内功：九阴真功	
			set_skill("jiuyin-shenfa",500);													//九阴轻功：九阴身法	
			set_skill("daode-jing",200);			
			map_skill("force", "jiuyin-zhengong");
			map_skill("dodge", "jiuyin-shenfa");
			u_f_pfm=u_f_pfm + ({(: exert_function, "yihuen" :)});   
			u_ub_pfm=u_ub_pfm + ({(: exert_function, "zongjue" :)});   							//九阴总诀
			u_f_pfm=u_f_pfm + ({(: perform_action, "dodge.huanyinbu" :)});      				//九阴身法pfm：幻阴步
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("jiuyin-baiguzhua",500);                              //九阴低级空手：九阴白骨爪
							map_skill("claw","jiuyin-baiguzhua");
							nw_parry="jiuyin-baiguzhua";
							prepare_skill("claw", "jiuyin-baiguzhua");
							u_pfm=u_pfm + ({(: perform_action, "claw.jiuyin" :)});			//九阴白骨爪pfm：九阴三绝爪
							set("f_skill","jiuyin-baiguzhua");       
						break;
						case 1:
							set_skill("cuixin-zhang",500);                             		//九阴低级空手：摧心掌
							map_skill("strike","cuixin-zhang");
							nw_parry="cuixin-zhang";
							prepare_skill("strike", "cuixin-zhang");
							u_pfm=u_pfm + ({(: perform_action, "strike.cuixin" :)});
							set("f_skill","cuixin-zhang");       							//摧心掌pfm：催心断肠
						break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("yinlong-bian",500);                                 //九阴低级兵器：九阴银龙鞭
							map_skill("whip","yinlong-bian");
							w_parry="yinlong-bian";
							u_w_pfm=u_w_pfm + ({(: perform_action, "whip.chanrao" :)});   	   //九阴银龙鞭pfm：缠绕诀
							u_w_pfm=u_w_pfm + ({(: perform_action, "whip.feilong" :)});        //飞龙  
							u_weapon="whip";
							set("f_w_skill","yinlong-bian");
						break;
					}
				break;
				case 1:
					switch(random(3))
					{
						case 0:
							set_skill("jiuyin-shenzhang",500);								//九阴高级空手：九阴神掌
							map_skill("strike","jiuyin-shenzhang");
							nw_parry="jiuyin-shenzhang";
							prepare_skill("strike","jiuyin-shenzhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.shenzhang" :)});   //九阴神掌pfm：神掌夺魄
							u_pfm = u_pfm + ({(: perform_action, "strike.yinyang" :)});		//阴阳双掌   
							set("f_skill","jiuyin-shenzhang");     
  						break;
  						case 1:
							set_skill("jiuyin-shenzhua",500);								//九阴高级空手：九阴神爪
							map_skill("claw","jiuyin-shenzhua");
							nw_parry="jiuyin-shenzhua";
							prepare_skill("claw","jiuyin-shenzhua");
							u_pfm = u_pfm + ({(: perform_action, "strike.sanjue" :)});      //九阴神爪pfm：九阴三绝爪
							set("f_skill","jiuyin-shenzhua");
  						break;
   						case 2:
							set_skill("dafumo-quan",500);								    //九阴高级空手：大伏魔拳
							map_skill("cuff","dafumo-quan");
							nw_parry="dafumo-quan";
							prepare_skill("cuff","dafumo-quan");
							u_pfm = u_pfm + ({(: perform_action, "cuff.fumo" :)});     		//大伏魔拳pfm：伏魔 
							set("f_skill","dafumo-quan");
  						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("xuanyin-jian",500);									//九阴高级兵器：玄阴剑法	
							map_skill("sword","xuanyin-jian");
							w_parry="xuanyin-jian";
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.xuanyin" :)});      //玄阴剑法pfm：玄阴诀 	
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.zhan" :)});			//斩字诀	
							u_weapon="sword";
							set("f_w_skill","xuanyin-jian");
						break;
					}					
				break;	
				}
			break;//end case 9y		
			case "hmg":
				set("family/family_name","蛤蟆功传人");		
				set_skill("hamagong",500);
				set_skill("lingshe-quanfa",500);
				set_skill("lingshe-zhangfa",500);
				map_skill("force","hamagong");
				map_skill("cuff","lingshe-quanfa");
				map_skill("staff","lingshe-zhangfa");
				map_skill("dodge","hamabu");
				prepare_skill("cuff","lingshe-quanfa");
				nw_parry="hamagong";
				set("oyf/hamagong",3);  	
				u_f_pfm = u_f_pfm + ({(: exert_function, "nizhuan" :)});  
				u_ub_pfm = u_ub_pfm + ({(: exert_function, "nizhuan" :)});      	
				set("f_skill","hamagong");
				switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
              set_skill("lingshe-quanfa",500);								//蛤蟆功空手：灵蛇拳法无pfm		
							map_skill("cuff","lingshe-quanfa");
							nw_parry="lingshe-quanfa";
							prepare_skill("cuff","lingshe-quanfa");
							set("f_skill","lingshe-quanfa");
							break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("lingshe-zhangfa",500);                               //蛤蟆功高级器械：灵蛇杖法
							map_skill("staff","lingshe-zhangfa");
							w_parry="lingshe-zhangfa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "staff.shoot" :)});          //蛤蟆功高级器械：喷毒
							u_weapon="staff";
							set("f_w_skill","lingshe-zhangfa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("lingshe-quanfa",500);                             //蛤蟆功高级空手：灵蛇拳法
							map_skill("cuff","lingshe-quanfa");
							nw_parry="lingshe-quanfa";
							prepare_skill("cuff", "lingshe-quanfa");
              u_pfm = u_pfm + ({(: perform_action, "cuff.lingshe" :)});     //灵蛇拳法pfm：灵蛇劲				
							set("f_skill","lingshe-quanfa");
							
							
							
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("lingshe-zhangfa",500);										//蛤蟆功高级器械：灵蛇杖法
							map_skill("staff","lingshe-zhangfa");
							w_parry="lingshe-zhangfa";
							u_w_pfm = u_w_pfm + ({(: perform_action, "staff.baibian" :)});			//灵蛇百变
							u_w_pfm = u_w_pfm + ({(: perform_action, "staff.luoye" :)});	//狂风扫落叶					
							u_weapon="staff";
							set("f_w_skill","lingshe-zhangfa");
						break;
					}					
				break;	
				}
			break;//end hmg
			case "pxj":
				set("family/family_name","东方不败的传人");		
				set("gender","无性");
				set_skill("pixie-jian",500);
				set_skill("hanbing-zhenqi",500);					//嵩山内功：寒冰真气			
				map_skill("force", "hanbing-zhenqi");
				map_skill("dodge", "pixie-jian");
				map_skill("sword", "pixie-jian");
				u_f_pfm=u_f_pfm + ({(: exert_function, "hanbing" :)});   //寒冰真气pfm：寒冰
				u_f_pfm=u_f_pfm + ({(: exert_function, "juhan" :)});     //聚寒
				u_f_pfm = u_f_pfm + ({(: perform_action, "sword.cimu" :)});        	
				u_f_pfm = u_f_pfm + ({(: perform_action, "dodge.feiying" :)});        	
				u_f_pfm = u_f_pfm + ({(: perform_action, "sword.jue" :)});        	
				w_parry="pixie-jian";
				u_weapon="xiuhua";
				set("f_w_skill","pixie-jian");
			break;//end pxj
			case "jsj":
				set("family/family_name","金蛇剑法的传人");		
				set_skill("zixia-gong",500);								//华山内功：紫霞功
				set_skill("huashan-shenfa",500);							//华山轻功：华山身法				
				set_skill("jinshe-jianfa",500);
				set_skill("jinshe-zhangfa",500);
				map_skill("force","zixia-gong");
				map_skill("dodge","huashan-shenfa");
				map_skill("sword","jinshe-jianfa");
				map_skill("strike","jinshe-zhangfa");
				prepare_skill("strike","jinshe-zhangfa");
				nw_parry="jinshe-zhangfa";
				w_parry="jinshe-jianfa";
				set("f_w_skill","jinshe-jianfa");
				set("f_skill","jinshe-zhangfa");
				u_weapon="sword";
				u_f_pfm = u_f_pfm + ({(: perform_action, "sword.kuangwu" :)});        	

				
			break;//end jsj
			case "rysj":											//设定日月神教的武功
			set("family/family_name","日月神教");
			set_skill("tianmo-gong",500);					//日月神教内功：天魔功
			set_skill("ding-dodge",500);						//日月神教轻功: 丁字步
			set_skill("tianmo-jue",200);                        //日月神教杂项：天魔诀
			map_skill("force", "tianmo-gong");              
			map_skill("dodge", "ding-dodge");
			u_f_pfm=u_f_pfm + ({(: exert_function, "richu" :)});             //天魔功exert:日出光华
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("tianmo-shou",500);                 //日月神教低级空手：天魔手
							map_skill("hand","tianmo-shou");
							nw_parry="tianmo-shou";
							prepare_skill("hand", "tianmo-shou");
							set("f_skill","tianmo-shou");
						break;
						case 1:
							set_skill("tianmo-zhang",500);          //日月神教低级空手：天魔掌 
							map_skill("strike","tianmo-zhang");
							nw_parry="tianmo-zhang";
							prepare_skill("strike","tianmo-zhang");
							set("f_skill","tianmo-zhang");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("tianmo-jian",500);                          //日月神教低级兵器：天魔剑
							map_skill("sword","tianmo-jian");
							w_parry="tianmo-jian";
							set("f_w_skill","tianmo-jian");
							u_weapon="sword";
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("tianmo-gun",500);                      	         	   //日月神教高级空手：天魔棍
							map_skill("club","tianmo-gun");
							nw_parry="tianmo-gun";
							prepare_skill("club","tianmo-gun");
							u_pfm = u_pfm + ({(: perform_action, "club.luanwu" :)});				//天魔棍pfm:神鬼乱舞
							u_pfm = u_pfm + ({(: perform_action, "club.tian" :)});			//天地旋转
							u_weapon="club";
							set("f_skill","tianmo-gun");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("tianmo-dao",500);										//日月神教高级兵器：天魔刀
							map_skill("sword","tianmo-dao");
							w_parry="tianmo-dao";
							u_w_pfm = u_w_pfm + ({(: perform_action, "blade.huashen" :)});				//天魔刀pfm：化身万千
							u_w_pfm = u_w_pfm + ({(: perform_action, "blade.jingshen" :)});			//惊神诀
							u_weapon="sword";
							set("f_w_skill","tianmo-dao");
						break;
					}					
				break;	
				}
			break;//end case rysj
			
					case "xxdf":												//设定吸星大法武功
			set("family/family_name","日月神教");
			set_skill("xixing-dafa",500);					//吸星大法内功：吸星大法			
			set_skill("piaomiao-shenfa",500);						//吸星大法轻功：缥缈身法
			map_skill("force", "xixing-dafa");
			map_skill("dodge", "piaomiao-shenfa");
			u_f_pfm=u_f_pfm + ({(: exert_function, "xixing" :)});   //吸星大法pfm：吸星大法
					switch(random(1))
					{
						case 0:
							set_skill("huanmo-longtianwu",500);                             //吸星大法高级空手：幻魔胧天舞
							map_skill("strike","huanmo-longtianwu");
							nw_parry="huanmo-longtianwu";
							prepare_skill("strike", "huanmo-longtianwu");
							u_pfm=u_pfm + ({(: perform_action, "strike.zhen" :)});        //幻魔胧天舞pfm：返璞归真
							set("f_skill","huanmo-longtianwu");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("qixian-wuxingjian",500);										//吸星大法高级兵器：七弦无形剑
							map_skill("sword","qixian-wuxingjian");
							w_parry="qixian-wuxingjian";
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.guangling" :)});        	//七弦无形剑pfm：广陵散曲
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.yin" :)});			//七弦无形音
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.shan" :)});			//七弦黄龙闪	
							u_weapon="sword";
							set("f_w_skill","qixian-wuxingjian");
						break;
					}					
			break;//end case xxdf	
			
			case "ljg":												//设定灵鹫宫武功
			set("family/family_name","灵鹫宫");
			set_skill("bahuang-gong",500);						//灵鹫宫内功：八荒六和唯我独尊			
			set_skill("yueying-wubu",500);					//灵鹫宫轻功：月影舞步
			set_skill("yangyanshu",500);						//灵鹫宫杂项：养颜术
			set("class","dancer");
			map_skill("force", "bahuang-gong");
			map_skill("dodge", "yueying-wubu");
			u_f_pfm=u_f_pfm + ({(: exert_function, "duzun" :)});   //八荒六和唯我独尊pfm：独尊

     
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("liuyang-zhang",500);                             //灵鹫宫低级空手：六阳掌
							map_skill("strike","liuyang-zhang");
							nw_parry="liuyang-zhang";
							prepare_skill("strike", "liuyang-zhang");
							set("f_skill","liuyang-zhang");
							break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("tianyu-qijian",500);                               //灵鹫宫低级武器：天羽奇剑
							map_skill("sword","tianyu-qijian");
							w_parry="tianyu-qijian";
							u_w_pfm=u_w_pfm + ({(: perform_action, "sword.kuangwu" :)});          //天羽奇剑pfm：天羽狂舞
							u_weapon="sword";
							set("f_w_skill","tianyu-qijian");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("zhemei-shou",500);								//灵鹫宫高级空手：截手九式		
							map_skill("hand","zhemei-shou");
							nw_parry="zhemei-shou";
							prepare_skill("hand","zhemei-shou");
							u_pfm = u_pfm + ({(: perform_action, "hand.tanmei" :)});     //截手九式pfm：寒冰
							set("f_skill","zhemei-shou");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("tianyu-qijian",500);										//灵鹫宫高级兵器：天羽奇剑
							map_skill("sword","tianyu-qijian");
							w_parry="tianyu-qijian";
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.shandian" :)});			//闪电
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.piaomiao" :)});				//飘渺诀
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.san" :)});				//散花								
							u_weapon="sword";
							set("f_w_skill","tianyu-qijian");
						break;
					}					
				break;	
				}
			break;//end case ljg
			
			case "xy":												//设定北冥神功武功
			set("family/family_name","逍遥派");
			set_skill("beiming-shengong",500);						//北冥神功内功：北冥神功			
			set_skill("piaomiao-shenfa",500);					//北冥神功轻功：凌波微步
			set_skill("taoism",200);						//北冥神功杂项：道学心法
			map_skill("force", "beiming-shengong");
			map_skill("dodge", "piaomiao-shenfa");
			u_f_pfm=u_f_pfm + ({(: exert_function, "beiming" :)});   //北冥神功pfm：北冥真气
			u_f_pfm=u_f_pfm + ({(: exert_function, "bing" :)});   //北冥神功pfm：冰心诀

     
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
              set_skill("zhemei-shou",500);								//逍遥高级空手：折梅手		
							map_skill("hand","zhemei-shou");
							nw_parry="zhemei-shou";
							prepare_skill("hand","zhemei-shou");
							set("f_skill","zhemei-shou");
							break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("ruyi-dao",500);                               //逍遥派低级武器：如意刀法
							map_skill("blade","ruyi-dao");
							w_parry="ruyi-dao";
							u_w_pfm=u_w_pfm + ({(: perform_action, "blade.wenrou" :)});          //如意刀法pfm：温柔一刀
							u_weapon="blade";
							set("f_w_skill","ruyi-dao");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("liuyang-zhang",500);                             //逍遥派低级空手：六阳掌
							map_skill("strike","liuyang-zhang");
							nw_parry="liuyang-zhang";
							prepare_skill("strike", "liuyang-zhang");
              u_pfm = u_pfm + ({(: perform_action, "strike.jiutian" :)});     //天山六阳掌pfm：九天乾阳		
              u_pfm = u_pfm + ({(: perform_action, "strike.baihong" :)});     //天山六阳掌pfm：白虹掌法						
							set("f_skill","liuyang-zhang");
							
							
							
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("ruyi-dao",500);										//逍遥高级兵器：如意刀法
							map_skill("blade","ruyi-dao");
							w_parry="ruyi-dao";
							u_w_pfm = u_w_pfm + ({(: perform_action, "blade.ruyi" :)});			//如意
							u_w_pfm = u_w_pfm + ({(: perform_action, "blade.xiaoyao" :)});				//逍遥					
							u_weapon="blade";
							set("f_w_skill","ruyi-dao");
						break;
					}					
				break;	
				}
			break;//end case qzj
			
			case "qzj":												//设定全真武功
			set("family/family_name","全真教");
			set_skill("xiantian-gong",500);						//全真内功：先天功			
			set_skill("jinyan-gong",500);					//全真轻功：金雁功
			set_skill("taoism",200);						//全真杂项：道学心法
			set("class","taoism");
			map_skill("force", "xiantian-gong");
			map_skill("dodge", "jinyan-gong");
			u_f_pfm=u_f_pfm + ({(: exert_function, "wuqi" :)});   //先天功pfm：五气朝元
			u_f_pfm=u_f_pfm + ({(: exert_function, "yiyang" :)});   //先天功pfm：一阳指剑气				

     
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
              set_skill("haotian-zhang",500);								//全真高级空手：昊天掌		
							map_skill("strike","haotian-zhang");
							nw_parry="haotian-zhang";
							prepare_skill("strike","haotian-zhang");
              u_pfm = u_pfm + ({(: perform_action, "strike.ju" :)});     //昊天掌pfm：三花聚顶									
							set("f_skill","haotian-zhang");
							break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("quanzhen-jianfa",500);                               //全真低级武器：全真剑法
							map_skill("sword","quanzhen-jianfa");
							w_parry="quanzhen-jianfa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "sword.qixing" :)});          //全真剑法pfm：七星剑
              u_w_pfm=u_w_pfm + ({(: perform_action, "sword.ding" :)});          //全真剑法pfm：定阳针								
							u_weapon="sword";
							set("f_w_skill","quanzhen-jianfa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
              set_skill("haotian-zhang",500);								//全真高级空手：昊天掌		
							map_skill("strike","haotian-zhang");
							nw_parry="haotian-zhang";
							prepare_skill("strike","haotian-zhang");
              u_pfm = u_pfm + ({(: perform_action, "strike.lianhuan" :)});     //昊天掌pfm：重阳连环掌						
							set("f_skill","haotian-zhang");
							
							
							
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("quanzhen-jianfa",500);                               //全真高级武器：全真剑法
							map_skill("sword","quanzhen-jianfa");
							w_parry="quanzhen-jianfa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "sword.sanqing" :)});          //全真剑法pfm：一剑化三清
              u_w_pfm=u_w_pfm + ({(: perform_action, "sword.lian" :)});          //全真剑法pfm：三连环	
              u_w_pfm=u_w_pfm + ({(: perform_action, "sword.jianjue" :)});          //全真剑法pfm：同归剑诀		
              u_w_pfm=u_w_pfm + ({(: perform_action, "sword.ding" :)});          //全真剑法pfm：定阳针	              								
							u_weapon="sword";
							set("f_w_skill","quanzhen-jianfa");
						break;
					}					
				break;	
				}
			break;//end case xy
	}//end whole switch		
}
