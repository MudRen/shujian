
#include <skills_pfm_set2.h>

void copy_menpai2()
{
	switch(u_menpai)
	{
		case "wd":											//�趨�䵱���书
			set("family/family_name","�䵱��");
			set_skill("yinyun-ziqi",500);					//�䵱�ڹ���������
			set_skill("tiyunzong",500);						//�䵱�Ṧ: ������
			set_skill("taoism",200);                        //�䵱�����ѧ�ķ�
			map_skill("force", "yinyun-ziqi");              
			map_skill("dodge", "tiyunzong");
			u_f_pfm=u_f_pfm + ({(: exert_function, "yinyun" :)});             //������pfm:���ھ�
			u_f_pfm=u_f_pfm + ({(: exert_function, "taiji" :)});             //̫��
			u_f_pfm=u_f_pfm + ({(: perform_action, "dodge.zong" :)});         //������pfm:��   
			switch(in_level)
			{
				case 0:
					switch(random(3))
					{
						case 0:
							set_skill("wudang-quan",500);                 //�䵱�ͼ����֣��䵱��ȭ
							map_skill("cuff","wudang-quan");
							nw_parry="wudang-quan";
							prepare_skill("cuff", "wudang-quan");
							set("f_skill","wudang-quan");
						break;
						case 1:
							set_skill("zhenshan-mianzhang",500);          //�䵱�ͼ����֣���ɽ���� 
							map_skill("strike","zhenshan-mianzhang");
							nw_parry="zhenshan-mianzhang";
							prepare_skill("strike","zhenshan-mianzhang");
							u_pfm=u_pfm + ({(: perform_action, "strike.bingdi" :)});  //��ɽ����pfm:��������
							set("f_skill","zhenshan-mianzhang");
						break;
						case 2:
							set_skill("juehu-shou",500);          
							map_skill("hand","juehu-shou");
							nw_parry="juehu-shou";
							prepare_skill("hand","juehu-shou");
							u_pfm=u_pfm + ({(: perform_action, "hand.juehu" :)});  //�䵱������pfm:����
							set("f_skill","juehu-shou");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("xuanxu-daofa",500);                          //�䵱�ͼ����������鵶��
							map_skill("blade","xuanxu-daofa");
							w_parry="xuanxu-daofa";
							set("f_w_skill","xuanxu-daofa");
							u_weapon="blade";
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("taiji-quan",500);                      	         	   //�䵱�߼����֣�̫��ȭ
							map_skill("cuff","taiji-quan");
							nw_parry="taiji-quan";
							prepare_skill("cuff","taiji-quan");
							u_pfm = u_pfm + ({(: perform_action, "cuff.ji" :)});				//̫��ȭpfm:��
							u_pfm = u_pfm + ({(: perform_action, "cuff.zhannian" :)});			//ճ�
							u_pfm = u_pfm + ({(: perform_action, "cuff.zhen" :)});				//��
							u_pfm = u_pfm + ({(: perform_action, "cuff.luanhuan" :)});			//�һ���
							u_pfm = u_pfm + ({(: perform_action, "cuff.yinyang" :)});			//������
							u_pfm = u_pfm + ({(: perform_action, "cuff.gangrou" :)});			//�����
							u_pfm = u_pfm + ({(: perform_action, "cuff.dongjing" :)});			//������
							u_pfm = u_pfm + ({(: perform_action, "cuff.an" :)});				//��
							set("f_skill","taiji-quan");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("taiji-jian",500);										//�䵱�߼�������̫����
							map_skill("sword","taiji-jian");
							w_parry="taiji-jian";
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.chan" :)});				//̫����pfm����
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.sanhuan" :)});			//��������
							//u_w_pfm = u_w_pfm + ({(: perform_action, "sword.lian" :)});				//��
							set("raozhi",1);
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.raozhi" :)});			//��ָ�ὣ
//							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.tongshou" :)});			//���ͬ��
							u_weapon="sword";
							set("f_w_skill","taiji-jian");
						break;
					}					
				break;	
				}
			break;//end case wd
		case "ss":												//�趨��ɽ�书
			set("family/family_name","��ɽ��");
			set_skill("hanbing-zhenqi",500);					//��ɽ�ڹ�����������			
			set_skill("zhongyuefeng",500);						//��ɽ�Ṧ��������
			map_skill("force", "hanbing-zhenqi");
			map_skill("dodge", "zhongyuefeng");
			u_f_pfm=u_f_pfm + ({(: exert_function, "hanbing" :)});   //��������pfm������
			u_f_pfm=u_f_pfm + ({(: exert_function, "juhan" :)});     //�ۺ�
			u_f_pfm=u_f_pfm + ({(: exert_function, "huti" :)});     //�����
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{

						case 0:
							set_skill("hanbing-shenzhang",500);								//��ɽ�ͼ����֣���������		
							map_skill("strike","hanbing-shenzhang");
							nw_parry="hanbing-shenzhang";
							prepare_skill("strike","hanbing-shenzhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.hanbing" :)});     //��������pfm������
							set("f_skill","hanbing-shenzhang");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("songyang-bian",500);                               //��ɽ�ͼ�������������
							map_skill("whip","songyang-bian");
							w_parry="songyang-bian";
							u_w_pfm=u_w_pfm + ({(: perform_action, "whip.luan" :)});          //������pfm����
							u_weapon="whip";
							set("f_w_skill","songyang-bian");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("songyang-shou",500);                             //��ɽ�߼����֣�������
							map_skill("hand","songyang-shou");
							nw_parry="songyang-shou";
							prepare_skill("hand", "songyang-shou");
							u_pfm=u_pfm + ({(: perform_action, "hand.junji" :)});        //������pfm������
							u_pfm=u_pfm + ({(: perform_action, "hand.yinyang" :)});      //����
							set("f_skill","songyang-shou");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("songshan-jian",500);										//��ɽ�߼���������ɽ����
							map_skill("sword","songshan-jian");
							w_parry="songshan-jian";
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.feiwu" :)});        	//��ɽ����pfm������
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.leiting" :)});			//�������
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.longfeng" :)});			//��������	
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.songyang" :)});			//������
							u_weapon="sword";
							set("f_w_skill","songshan-jian");
						break;
					}					
				break;	
				}
			break;//end case ss			
		case "gb":                                                      //�趨ؤ���书
			set("family/family_name","ؤ��");
			set_skill("huntian-qigong",500);							//ؤ���ڹ�������һ����
			set_skill("xiaoyaoyou",500);								//ؤ���Ṧ����ң��	
			set_skill("begging",200);			
			set("death_times",50);								
			set_skill("bangjue",200);
			set_skill("stealing",200);
			set_skill("checking",200);									//ؤ�����begging��bangjue��stealing��checking		
			map_skill("force", "huntian-qigong");
			map_skill("dodge", "xiaoyaoyou");
			u_f_pfm=u_f_pfm + ({(: exert_function, "huntian" :)});          //��������:����
			u_f_pfm=u_f_pfm + ({(: exert_function, "shougong" :)}); 		//�չ�
			u_f_pfm=u_f_pfm + ({(: exert_function, "shentong" :)}); 		//��ͨ
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("lianhua-zhang",500);				//ؤ��ͼ����֣�������
							map_skill("strike","lianhua-zhang");
							nw_parry="lianhua-zhang";
							prepare_skill("strike", "lianhua-zhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.bingdi" :)});   //��������
							u_pfm = u_pfm + ({(: perform_action, "strike.cailian" :)});   //����
							set("f_skill","lianhua-zhang");
						break;
						case 1:
							set_skill("suohou-shou",500);              //ؤ��ͼ����֣�������
							map_skill("hand","suohou-shou");
							nw_parry="suohou-shou";
							prepare_skill("hand", "suohou-shou");
							set("f_skill","suohou-shou");
						break;
							

					}
					switch(random(3))
					{
						case 0:
							set_skill("huifeng-bian",500);                                //ؤ��ͼ��������ط��
							map_skill("whip","huifeng-bian");
							w_parry="huifeng-bian";
							u_w_pfm=u_w_pfm + ({(: perform_action, "whip.huixuan" :)});       //�ط��pfm���ط�
							u_weapon="whip";
							set("f_w_skill","huifeng-bian");
						break;
						case 1:
							set_skill("liuhe-daofa",500);								  //ؤ��ͼ���������������				
							map_skill("blade","liuhe-daofa");
							w_parry="liuhe-daofa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "blade.sancai" :)});       //��������pfm����������	
							u_weapon="blade";
							set("f_w_skill","liuhe-daofa");
						break;
						case 2:
							set_skill("fengmo-zhang",500);								  //ؤ��ͼ���������ħ��
							set("shen",-2000);
							map_skill("staff","fengmo-zhang");
							w_parry="fengmo-zhang";
							u_weapon="staff";
							u_w_pfm=u_w_pfm + ({(: perform_action, "staff.feizhang" :)});       //��������
							set("f_w_skill","fengmo-zhang");
						break;
					}
				break;
				case 1:
					switch(random(2))
					{
						case 0:
							set_skill("xianglong-zhang",500);								//ؤ��߼����֣�������
							map_skill("strike","xianglong-zhang");
							nw_parry="xianglong-zhang";
							prepare_skill("strike","xianglong-zhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.paiyun" :)});         //������pfm������˫��
							u_pfm = u_pfm + ({(: perform_action, "strike.xiao" :)});		//Х
							u_pfm = u_pfm + ({(: perform_action, "strike.kanglong" :)});	//�����޻�
							set("xlz/hang",1);              								//������������
							set("f_skill","xianglong-zhang");

						break;
						case 1:
							set_skill("taizu-quan",500);								//ؤ��߼����֣�������
							map_skill("strike","taizu-quan");
							nw_parry="taizu-quan";
							prepare_skill("cuff","taizu-quan");
							//u_pfm = u_pfm + ({(: perform_action, "cuff.qianjun" :)});         //������pfm������˫��        							
							set("f_skill","taizu-quan");

						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("dagou-bang",500);									//ؤ��߼��������򹷰���
							set_skill("dagou-bang",500);
							map_skill("stick","dagou-bang");
							w_parry="dagou-bang";
							//u_w_pfm = u_w_pfm + ({(: perform_action, "stick.chan" :)});       	//�򹷰���pfm����
							//u_w_pfm = u_w_pfm + ({(: perform_action, "stick.chuo" :)});			//��
							u_w_pfm = u_w_pfm + ({(: perform_action, "stick.shuangjue" :)});	//����˫��
							u_w_pfm = u_w_pfm + ({(: perform_action, "stick.tiao" :)});			//��
							//u_w_pfm = u_w_pfm + ({(: perform_action, "stick.zhuan" :)});		//ת
							u_w_pfm = u_w_pfm + ({(: perform_action, "stick.wugou" :)});		//�����޹�
							u_w_pfm = u_w_pfm + ({(: perform_action, "stick.yin" :)});		//��
							//u_w_pfm = u_w_pfm + ({(: perform_action, "stick.ban" :)});		//�� ȡ�������ر�bt��
							u_w_pfm = u_w_pfm + ({(: perform_action, "stick.pi" :)});							
							u_weapon="stick";
							set("f_w_skill","dagou-bang");
						break;
					}					
				break;	
				}
			break;//end case gb		
		case "hs":                                                      //�趨��ɽ�书
			set("family/family_name","��ɽ��");
			set_skill("zixia-gong",500);								//��ɽ�ڹ�����ϼ��
			set_skill("huashan-shenfa",500);							//��ɽ�Ṧ����ɽ��	
			set_skill("zhengqi-jue",200);								//��ɽ���������			
			map_skill("force", "zixia-gong");
			map_skill("dodge", "huashan-shenfa");
			u_f_pfm=u_f_pfm + ({(: exert_function, "zixia" :)});            //��ϼ��pfm��zixia    
		  u_f_pfm=u_f_pfm + ({(: exert_function, "jianqi" :)});            //��ϼ��pfm��jianqi  
	    u_f_pfm=u_f_pfm + ({(: exert_function, "jianyi" :)});            //��ϼ��pfm��jianyi
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("poyu-quan",500);				//��ɽ�ͼ����֣�����ȭ
							map_skill("cuff","poyu-quan");
							nw_parry="poyu-quan";
							prepare_skill("cuff", "poyu-quan");
							u_pfm=u_pfm + ({(: perform_action, "cuff.leidong" :)});       //�׶�����
							set("f_skill","poyu-quan");
						break;
					}
					switch(random(2))
					{
						case 0:
							set_skill("fanliangyi-dao",500);                              //��ɽ�ͼ������������ǵ���
							map_skill("blade","fanliangyi-dao");
							w_parry="fanliangyi-dao";
							u_w_pfm=u_w_pfm + ({(: perform_action, "blade.sanshenfeng" :)});       //�����ǵ���pfm�����������
							u_weapon="blade";
							set("f_w_skill","fanliangyi-dao");
						break;
						case 1:
							set_skill("chongling-jian",500);                              //��ɽ�ͼ����������齣��
							map_skill("sword","chongling-jian");
							w_parry="chongling-jian";
//							u_w_pfm=u_w_pfm + ({(: perform_action, "sword.hebi" :)});       //���齣��pfm���ϱ�
							u_weapon="sword";
							set("f_w_skill","chongling-jian");
						break;			
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("hunyuan-zhang",500);				//��ɽ�ͼ����֣���Ԫ��
							map_skill("strike","hunyuan-zhang");
							nw_parry="hunyuan-zhang";
							prepare_skill("strike", "hunyuan-zhang");
							u_pfm=u_pfm + ({(: perform_action, "strike.wuji" :)});       //��Ԫ��pfm����Ԫ�޼�
							set("f_skill","hunyuan-zhang");
						break;
					}
					switch(random(2))
					{
						case 0:
							set_skill("huashan-jianfa",500);								//��ɽ�߼���������ɽ����
							map_skill("sword","huashan-jianfa");
							w_parry="huashan-jianfa";
//							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.fengyi" :)});     	//�з�����
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.luomu" :)});		//�ޱ���ľ
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.kuaijian" :)});		//�콣
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.lianhuan" :)});		//����
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.cangsong" :)});	//����ӭ��
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.shijiushi" :)});	//ʮ��ʽ
//							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.shunv" :)});		//��Ů
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.wushuang" :)});		//��˫
//							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.xiyi" :)});			//ϣ��
//							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.yangwu" :)});		//����
							u_weapon="sword";
							set("f_w_skill","huashan-jianfa");
						break;
						case 1:
							set_skill("dugu-jiujian",500);								//��ɽ�߼����������¾Ž�
							map_skill("dodge","dugu-jiujian");
							map_skill("sword","dugu-jiujian");
							w_parry="dugu-jiujian";
//							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.kuangfeng" :)});    //���¾Ž�pfm�����
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.poqi" :)});	
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.pozhao" :)});	
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.zongjue" :)});		//�ܾ�
							u_weapon="sword";
							set("f_w_skill","dugu-jiujian");
						break;
					}					
				break;	
				}
			break;//end case hs
		case "tz":												//�趨�����书
			set("family/family_name","���ư�");
			set_skill("guiyuan-tunafa",500);					//�����ڹ�����Ԫ���ɷ�			
			set_skill("shuishangpiao",500);						//�����Ṧ��ˮ��Ư
			set_skill("tiezhang-xinfa",200);					//������������ķ�
			map_skill("force", "guiyuan-tunafa");
			map_skill("dodge", "shuishangpiao");
			u_f_pfm=u_f_pfm + ({(: exert_function, "guiyuan" :)});          //��������pfm������
			u_f_pfm=u_f_pfm + ({(: perform_action, "dodge.piao" :)});     //ˮ��Ưpfm:Ư
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("tiezhang-zhangfa",500);								//���Ƹ߼����֣������Ʒ�		
							map_skill("strike","tiezhang-zhangfa");							//tz �޵ͼ����֣����Եͼ�����Ҳ�������Ʒ�
							nw_parry="tiezhang-zhangfa";
							prepare_skill("strike","tiezhang-zhangfa");
							u_pfm = u_pfm + ({(: perform_action, "strike.duoming" :)});     //�����Ʒ�pfm��������צ
							u_pfm = u_pfm + ({(: perform_action, "strike.heisha" :)});     //�����Ʒ�pfm���� ɰ ��
							u_pfm = u_pfm + ({(: perform_action, "strike.heyi" :)});     //�����Ʒ�pfm��������һ
							u_pfm = u_pfm + ({(: perform_action, "strike.honglei" :)});     //�����Ʒ�pfm������˫��
							u_pfm = u_pfm + ({(: perform_action, "strike.judu" :)});     //�����Ʒ�pfm����    ��
							u_pfm = u_pfm + ({(: perform_action, "strike.pangen" :)});     //�����Ʒ�pfm�������̸�
							u_pfm = u_pfm + ({(: perform_action, "strike.pushan" :)});     //�����Ʒ�pfm����������
							u_pfm = u_pfm + ({(: perform_action, "strike.qinna" :)});     //�����Ʒ�pfm����������
							u_pfm = u_pfm + ({(: perform_action, "strike.rubairen" :)});     //�����Ʒ�pfm���� �� ��
							u_pfm = u_pfm + ({(: perform_action, "strike.tianlei" :)});     //�����Ʒ�pfm���� �� ��
							u_pfm = u_pfm + ({(: perform_action, "strike.xuanfeng" :)});     //�����Ʒ�pfm���������
							u_pfm = u_pfm + ({(: perform_action, "strike.zhangdao" :)});     //�����Ʒ�pfm�������Ƶ�
							u_pfm = u_pfm + ({(: perform_action, "strike.tiezhang" :)});     //�����Ʒ�pfm������
							set("f_skill","tiezhang-zhangfa");
						break;
					}				
					switch(random(2))
					{
						case 0:
							set_skill("liuye-daofa",500);                               //���Ƶͼ���������Ҷ����
							map_skill("blade","liuye-daofa");
							w_parry="liuye-daofa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "blade.daozhang" :)});   //��Ҷ����pfm������
							u_weapon="blade";											//��Ҫ�����Ʒ�Ϊ�мܣ�����prepare
							set("f_w_skill","liuye-daofa");
						break;
						case 1:
							set_skill("yingou-bifa",500);                               //���Ƶͼ������������ʷ�
							map_skill("brush","yingou-bifa");
							w_parry="yingou-bifa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "brush.caoshu" :)});  	//�����ʷ�pfm������
							u_w_pfm=u_w_pfm + ({(: perform_action, "brush.kaishu" :)});  	//�����ʷ�pfm������
							u_w_pfm=u_w_pfm + ({(: perform_action, "brush.shigu" :)});  	//�����ʷ�pfm������
							u_weapon="brush";
							set("f_w_skill","yingou-bifa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("tiezhang-zhangfa",500);								//���Ƹ߼����֣������Ʒ�		
							map_skill("strike","tiezhang-zhangfa");
							nw_parry="tiezhang-zhangfa";
							prepare_skill("strike","tiezhang-zhangfa");
							u_pfm = u_pfm + ({(: perform_action, "strike.duoming" :)});     //�����Ʒ�pfm��������צ
							u_pfm = u_pfm + ({(: perform_action, "strike.heisha" :)});     //�����Ʒ�pfm���� ɰ ��
							u_pfm = u_pfm + ({(: perform_action, "strike.heyi" :)});     //�����Ʒ�pfm��������һ
							u_pfm = u_pfm + ({(: perform_action, "strike.honglei" :)});     //�����Ʒ�pfm������˫��
							u_pfm = u_pfm + ({(: perform_action, "strike.judu" :)});     //�����Ʒ�pfm����    ��
							u_pfm = u_pfm + ({(: perform_action, "strike.pangen" :)});     //�����Ʒ�pfm�������̸�
							u_pfm = u_pfm + ({(: perform_action, "strike.pushan" :)});     //�����Ʒ�pfm����������
							u_pfm = u_pfm + ({(: perform_action, "strike.qinna" :)});     //�����Ʒ�pfm����������
							u_pfm = u_pfm + ({(: perform_action, "strike.rubairen" :)});     //�����Ʒ�pfm���� �� ��
							u_pfm = u_pfm + ({(: perform_action, "strike.tianlei" :)});     //�����Ʒ�pfm���� �� ��
							u_pfm = u_pfm + ({(: perform_action, "strike.xuanfeng" :)});     //�����Ʒ�pfm���������
							u_pfm = u_pfm + ({(: perform_action, "strike.zhangdao" :)});     //�����Ʒ�pfm�������Ƶ�
							u_pfm = u_pfm + ({(: perform_action, "strike.tiezhang" :)});     //�����Ʒ�pfm������
							set("f_skill","tiezhang-zhangfa");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("lietian-fu",500);                               //���Ƹ߼����������츫
							map_skill("axe","lietian-fu");
							w_parry="lietian-fu";
							u_w_pfm=u_w_pfm + ({(: perform_action, "axe.lihun" :)});  		//���츫pfm�����
							u_weapon="axe";
							set("f_w_skill","lietian-fu");
						break;
					}					
				break;	
				}
			break;//end case tz
			
		case "dls":												//�趨�������书
			set("family/family_name","������");
			set_skill("longxiang-boruo",500);					//�������ڹ������������			
			set_skill("yuxue-dunxing",500);						//�������Ṧ����ѩ����
			set_skill("huanxi-chan",200);						//�����������ϲ��
			map_skill("force", "longxiang-boruo");
			map_skill("dodge", "yuxue-dunxing");
			u_f_pfm=u_f_pfm + ({(: exert_function, "longxiang" :)});   //���������pfm������
			u_f_pfm=u_f_pfm + ({(: exert_function, "shield" :)});      //����
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("dashou-yin",500);                             //�����µͼ����֣�����ӡ
							map_skill("hand","dashou-yin");
							nw_parry="dashou-yin";
							prepare_skill("hand", "dashou-yin");
							u_pfm=u_pfm + ({(: perform_action, "hand.tianyin" :)});  //����ӡpfm����������ӡ
							set("f_skill","dashou-yin");
						break;
						case 1:
							set_skill("tianwang-zhua",500);                             //�����µͼ����֣�����ӡ
							map_skill("claw","tianwang-zhua");
							nw_parry="tianwang-zhua";
							prepare_skill("claw", "tianwang-zhua");
							set("f_skill","tianwang-zhua");
						break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("wushang-dali",500);                               //�����µͼ����������ϴ�����
							map_skill("staff","wushang-dali");
							w_parry="wushang-dali";
							u_weapon="staff";
							set("f_w_skill","wushang-dali");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("huoyan-dao",500);								//�����¸߼����֣����浶		
							map_skill("strike","huoyan-dao");
							nw_parry="huoyan-dao";
							prepare_skill("strike","huoyan-dao");
							u_pfm = u_pfm + ({(: perform_action, "strike.fen" :)});     //���浶pfm����
							u_pfm = u_pfm + ({(: perform_action, "strike.daoqi" :)});
							u_pfm = u_pfm + ({(: perform_action, "strike.ran" :)});
							set("f_skill","huoyan-dao");
						break;
					}
					switch(random(2))
					{
						case 0:
							set_skill("xuedao-jing",500);										//�����¸߼�������Ѫ����
							map_skill("blade","xuedao-jing");
							w_parry="xuedao-jing";
							set("env/jixue",random(5)+1);                                       //pfm ��Ѫ��������
							u_w_pfm = u_w_pfm + ({(: perform_action, "blade.jixue" :)});        	//pfm ��Ѫ
							u_w_pfm = u_w_pfm + ({(: perform_action, "blade.shendao" :)});			//�񵶴���
							u_weapon="blade";
							set("f_w_skill","xuedao-jing");
						break;
						case 1:
							set_skill("xiangfu-lun",500);										//�����¸߼�������������
							map_skill("hammer","xiangfu-lun");
							w_parry="xiangfu-lun";
							u_w_pfm = u_w_pfm + ({(: perform_action, "hammer.wushuai" :)});        	//������˥
							u_w_pfm = u_w_pfm + ({(: perform_action, "hammer.dazhuan" :)});			//��ת
							u_weapon="hammer";
							set("f_w_skill","xiangfu-lun");
						break;
					}					
				break;	
				}
			break;//end case dls				
		case "gm":												//�趨��Ĺ�书
			set("family/family_name","��Ĺ��");
			set_skill("yunu-xinjing",500);						//��Ĺ�ڹ�����Ů�ľ�			
			set_skill("yunu-shenfa",500);						//��Ĺ�Ṧ����Ů��
			map_skill("force", "yunu-xinjing");
			map_skill("dodge", "yunu-shenfa");
			u_ub_pfm=u_ub_pfm + ({(: exert_function, "xinjing" :)});  //��Ů�ľ�pfm��xinjing
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("tianluo-diwang",500);                             //��Ĺ�ͼ����֣����޵���ʽ
							map_skill("strike","tianluo-diwang");
							nw_parry="tianluo-diwang";
							prepare_skill("strike", "tianluo-diwang");
							set("f_skill","tianluo-diwang");
						break;
						case 1:
							set_skill("meinu-quanfa",500);                          		 //��Ĺ�ͼ����֣���Ůȭ��
							map_skill("cuff","meinu-quanfa");
							nw_parry="meinu-quanfa";
							prepare_skill("cuff", "meinu-quanfa");
							u_pfm = u_pfm + ({(: perform_action, "cuff.shexin" :)});		//��Ůȭ��pfm:����
							set("f_skill","meinu-quanfa");
						break;

					}
					switch(random(2))
					{
						case 0:
							set_skill("yunu-jianfa",500);                               //��Ĺ�ͼ���������Ů���Ľ�
							map_skill("sword","yunu-jianfa");
							w_parry="yunu-jianfa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "sword.suxin" :)});      //��Ů���Ľ�pfm������
							u_weapon="sword";
							set("f_w_skill","yunu-jianfa");
						break;
						case 1:
							set_skill("quanzhen-jianfa",500);                               //��Ĺ�ͼ�������ȫ�潣��
							map_skill("sword","quanzhen-jianfa");
							w_parry="quanzhen-jianfa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "sword.qixing" :)});     	//ȫ�潣��pfm�����Ǿ۶�
							u_w_pfm=u_w_pfm + ({(: perform_action, "sword.sanqing" :)});   	    //�����
							u_weapon="sword";
							set("f_w_skill","quanzhen-jianfa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("anran-zhang",500);								//��Ĺ�߼����֣���Ȼ������		
							map_skill("strike","anran-zhang");
							nw_parry="anran-zhang";
							prepare_skill("strike","anran-zhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.anran" :)});     //��Ȼ������pfm����Ȼ
							u_pfm = u_pfm + ({(: perform_action, "strike.jishi" :)});     //��Ȼ������pfm������
							u_pfm = u_pfm + ({(: perform_action, "strike.xiaohun" :)});     //��Ȼ������pfm������
							set("f_skill","anran-zhang");
						break;
					}
					switch(random(2))
					{
						case 0:
							set_skill("xuantie-jianfa",500);									//��Ĺ�߼���������������
							map_skill("sword","xuantie-jianfa");
							w_parry="xuantie-jianfa";
							set("env/��������",random(2)?"����":"��ӿ");						//pfm ����������趨
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.haichao" :)});        	//����pfm������
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.wujian" :)});			//�޽�
							u_weapon="sword";
							set("f_w_skill","xuantie-jianfa");
						break;
						case 1:
							set_skill("yinsuo-jinling",500);									//��Ĺ�߼���������������
							if(in_weapon)
							{
								pmap = query_skill_prepare();
								if (sizeof(pmap))
								{
									skill = keys(pmap);
									foreach (string item in skill)
									prepare_skill(item);
								}							
								set_skill("meinu-quanfa",500);										//pfm sanwu������֮һ
								map_skill("cuff","meinu-quanfa");
								prepare_skill("cuff", "meinu-quanfa");
								set("f_skill","meinu-quanfa");
							}
							map_skill("whip","yinsuo-jinling");
							set("gmsanwu",1);
							w_parry="yinsuo-jinling";
							//u_w_pfm = u_w_pfm + ({(: perform_action, "whip.sanwu" :)});        	//��������pfm������������
							u_w_pfm = u_w_pfm + ({(: perform_action, "whip.yueyin" :)});			//yueyin
							u_weapon="whip";
							set("f_w_skill","yinsuo-jinling");
						break;
					}					
				break;	
				}
			break;//end case gm	

		case "mr":												//�趨Ľ���书
			set("family/family_name","����Ľ��");
			set_skill("shenyuan-gong",500);					//Ľ���ڹ�����Ԫ��			
			set_skill("yanling-shenfa",500);						//Ľ���Ṧ��������
			set_skill("douzhuan-xingyi",500);						//��ת����
			map_skill("force", "shenyuan-gong");
			map_skill("dodge", "yanling-shenfa");
			u_f_pfm=u_f_pfm + ({(: exert_function, "shenyuan" :)});   		//��Ԫ��pfm����Ԫ
//			u_f_pfm=u_f_pfm + ({(: perform_action, "parry.xingyi" :)});     //��ת����pfm������
			u_f_pfm=u_f_pfm + ({(: perform_action, "parry.bishen" :)});		//�Ա�֮�� ��ʩ����

			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("xingyi-zhang",500);                             //Ľ�ݵͼ����֣�������
							map_skill("strike","xingyi-zhang");
							nw_parry="xingyi-zhang";
							prepare_skill("strike", "xingyi-zhang");
							u_pfm=u_pfm + ({(: perform_action, "strike.riyue" :)});        //������pfm������ͬ��
							set("f_skill","xingyi-zhang");
							break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("murong-daofa",500);                               //Ľ�ݵͼ�������Ľ�ݵ���
							map_skill("blade","murong-daofa");
							w_parry="murong-daofa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "blade.daoying" :)});     //Ľ�ݵ���pfm����Ӱ��
							u_w_pfm=u_w_pfm + ({(: perform_action, "blade.luandao" :)});
							u_weapon="blade";
							set("f_w_skill","murong-daofa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("canhe-zhi",500);								//Ľ�ݸ߼����֣��κ�ָ
							map_skill("finger","canhe-zhi");
							nw_parry="douzhuan-xingyi";                             //ֻ���ڲκ�ָ������£������趨douzhuan-xingyiΪparry���ҷ�pfm 
							prepare_skill("finger","canhe-zhi");
							u_pfm = u_pfm + ({(: perform_action, "finger.ci" :)});     //�κ�ָpfm����
							set("f_skill","canhe-zhi");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("murong-jianfa",500);										//Ľ�ݸ߼�������Ľ�ݽ���
							map_skill("sword","murong-jianfa");
							w_parry="murong-jianfa";
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.lianhuan" :)});        	//Ľ�ݽ���pfm������
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.sanhua" :)});			//ɢ��
							u_weapon="sword";
							set("f_w_skill","murong-jianfa");
						break;
					}					
				break;	
				}
			break;//end case mr				
			
		case "sld":												//�趨�������书
			set("family/family_name","������");
			set("family/master_id","hong antong");
			set_skill("dulong-dafa",500);						//�������ڹ��������� 			
			set_skill("youlong-shenfa",500);					//�������Ṧ��������
			set_skill("shenlong-yaoli",200);					//�������������ҩ��ѧ
			map_skill("force", "dulong-dafa");
			map_skill("dodge", "youlong-shenfa");
			u_f_pfm=u_f_pfm + ({(: exert_function, "wudi" :)});   		//������pfm���޵�	
			switch(in_level)
			{
				case 0:
					switch(random(2))
					{
						case 0:
							set_skill("hansha-sheying",500);                             //�������ͼ����֣���ɳ��Ӱ
							map_skill("throwing","hansha-sheying");
							nw_parry="hansha-sheying";
							prepare_skill("throwing", "hansha-sheying");
							set("f_skill","hansha-sheying");
						break;
						case 1:
							set_skill("shenlong-tuifa",500);                             //�������ͼ����֣������ȷ�
							map_skill("leg","shenlong-tuifa");
							nw_parry="shenlong-tuifa";
							prepare_skill("leg", "shenlong-tuifa");
//							set("env/zhuiming",random(60)+1);
//							u_pfm=u_pfm + ({(: perform_action, "leg.zhuiming" :)});          //�����ȷ�pfm��׷��
							set("f_skill","shenlong-tuifa");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("lingshe-bianfa",500);                               //�������ͼ����������߱޷�
							map_skill("whip","lingshe-bianfa");
							w_parry="lingshe-bianfa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "whip.chan" :)});          //���߱޷�pfm������
							u_w_pfm=u_w_pfm + ({(: perform_action, "whip.sandou" :)});        //���߱޷�pfm������
							u_weapon="whip";
							set("f_w_skill","lingshe-bianfa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("huagu-mianzhang",500);								//�������߼����֣���������
							map_skill("strike","huagu-mianzhang");
							nw_parry="huagu-mianzhang";
							prepare_skill("strike","huagu-mianzhang");
//							u_pfm = u_pfm + ({(: perform_action, "strike.bujue" :)});     //��������pfm������
							u_pfm = u_pfm + ({(: perform_action, "strike.huagu" :)});     //��������pfm������
//							u_pfm = u_pfm + ({(: perform_action, "strike.puhuo" :)});     //��������pfm���ɶ��˻�
							set("f_skill","huagu-mianzhang");

						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("tenglong-bifa",500);										//�������߼�����������ذ��
							map_skill("dagger","tenglong-bifa");
							w_parry="tenglong-bifa";
							//u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.diqing" :)});        	//����ذ��pfm�����ཱུ�� ȡ��
							u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.feiyan" :)});			//�������
							u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.guifei" :)});			//��������	
							//u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.luda" :)});			//³�����
							u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.xiaolian" :)});		//С�����
							u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.zixu" :)});			//����ٶ�
							u_weapon="dagger";
							set("f_w_skill","tenglong-bifa");
						break;
					}					
				break;	
				}
			break;//end case sld		

		case "xx":												//�趨�����书
			set("family/family_name","������");
			set_skill("huagong-dafa",500);						//�����ڹ���������			
			set_skill("zhaixingshu",500);						//�����Ṧ��ժ���� 
			map_skill("force", "huagong-dafa");
			map_skill("dodge", "zhaixingshu");
//			u_f_pfm=u_f_pfm + ({(: exert_function, "duwu" :)});   //������pfm������
			set_skill("poison",200);						  // judu need poison >150							
			u_f_pfm=u_f_pfm + ({(: exert_function, "judu" :)});   //�۶�
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("sanyin-zhua",500);                             //���޵ͼ����֣��������צ
							map_skill("claw","sanyin-zhua");
							nw_parry="sanyin-zhua";
							prepare_skill("claw", "sanyin-zhua");
							u_pfm = u_pfm + ({(: perform_action, "claw.sanyin" :)});
							set("f_skill","sanyin-zhua");
							break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("tianshan-zhang",500);										//���޸߼���������ɽ�ȷ�
							map_skill("staff","tianshan-zhang");
							w_parry="tianshan-zhang";
							u_w_pfm = u_w_pfm + ({(: perform_action, "staff.feizhi" :)});        	//��ɽ�ȷ�pfm������
							u_weapon="staff";
							set("f_w_skill","tianshan-zhang");
						break;
					}	
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("chousui-zhang",500);								//���޸߼����֣�������		
							map_skill("strike","chousui-zhang");
							nw_parry="chousui-zhang";
							prepare_skill("strike","chousui-zhang");
							u_pfm = u_pfm + ({(: perform_action, "strike.biyan" :)});     //������pfm������
//							u_pfm = u_pfm + ({(: perform_action, "strike.fushidu" :)});     //������pfm����ʬ��
							u_pfm = u_pfm + ({(: perform_action, "strike.huoqiang" :)});     //������pfm����ǽ
							u_pfm = u_pfm + ({(: perform_action, "strike.huoqiu" :)});     //������pfm������
							u_pfm = u_pfm + ({(: perform_action, "strike.yinhuo" :)});     //������pfm������
							set("f_skill","chousui-zhang");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("tianshan-zhang",500);										//���޸߼���������ɽ�ȷ�
							map_skill("staff","tianshan-zhang");
							w_parry="tianshan-zhang";
							u_w_pfm = u_w_pfm + ({(: perform_action, "staff.feizhi" :)});        	//��ɽ�ȷ�pfm������
							u_weapon="staff";
							set("f_w_skill","tianshan-zhang");
						break;
					}					
				break;	
				}
			break;//end case xx
			
		case "em":												//�趨��ü�书
			set("family/family_name","������");
			set_skill("linji-zhuang",500);						//��ü�ڹ����ټ�ʮ��ׯ			
			set_skill("anying-fuxiang",500);					//��ü�Ṧ����Ӱ����
			set_skill("dacheng-fofa",500);						//��ü�����˷�
			set("class","bonze");
			map_skill("force", "linji-zhuang");
			map_skill("dodge", "anying-fuxiang");
			u_f_pfm=u_f_pfm + ({(: exert_function, "fengyun" :)});   //�ټ�ʮ��ׯpfm������
			u_f_pfm=u_f_pfm + ({(: exert_function, "riyue" :)});	 //����
			u_f_pfm=u_f_pfm + ({(: exert_function, "tiandi" :)});    //��� 
			u_f_pfm=u_f_pfm + ({(: exert_function, "wuwo" :)});      //����
			u_f_pfm=u_f_pfm + ({(: exert_function, "yinyang" :)});   //����  
			if(random(5)==1)
			u_f_pfm=u_f_pfm + ({(: exert_function, "youming" :)});   //��ڤ  
			u_f_pfm=u_f_pfm + ({(: exert_function, "zhixin" :)});    //֮�� 
			u_f_pfm=u_f_pfm + ({(: perform_action, "dodge.huashen" :)});   //���컯��

     
			switch(in_level)
			{
				case 0:
					switch(random(1))
					{
						case 0:
							set_skill("sixiang-zhang",500);                             //��ü�ͼ����֣�������
							map_skill("strike","sixiang-zhang");
							nw_parry="sixiang-zhang";
							prepare_skill("strike", "sixiang-zhang");
							set("f_skill","sixiang-zhang");
							break;

					}
					switch(random(1))
					{
						case 0:
							set_skill("yanxing-daofa",500);                               //��ü�ͼ����������е���
							map_skill("blade","yanxing-daofa");
							w_parry="yanxing-daofa";
							u_w_pfm=u_w_pfm + ({(: perform_action, "blade.feiyang" :)});          //���е���pfm������
							u_w_pfm=u_w_pfm + ({(: perform_action, "blade.huanying" :)});         //���е���pfm����Ӱ
							u_w_pfm=u_w_pfm + ({(: perform_action, "blade.chuanliu" :)});		  // ���д�����
							u_weapon="blade";
							set("f_w_skill","yanxing-daofa");
						break;
					}
				break;
				case 1:
					switch(random(1))
					{
						case 0:
							set_skill("jieshou-jiushi",500);								//��ü�߼����֣����־�ʽ		
							map_skill("hand","jieshou-jiushi");
							nw_parry="jieshou-jiushi";
							prepare_skill("hand","jieshou-jiushi");
							u_pfm = u_pfm + ({(: perform_action, "hand.foguang" :)});     //���־�ʽpfm������
							set("f_skill","jieshou-jiushi");
						break;
					}
					switch(random(1))
					{
						case 0:
							set_skill("huifeng-jian",500);										//��ü�߼��������ط������
							map_skill("sword","huifeng-jian");
							w_parry="huifeng-jian";
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.jue" :)});        		//�ط������pfm����
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.liaoyuan" :)});			//��ԭ
							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.miejue" :)});				//���
							u_weapon="sword";
							set("f_w_skill","huifeng-jian");
						break;
					}					
				break;	
				}
			break;//end case em
		}
	/////////
	copy_menpai3();
}

		
		