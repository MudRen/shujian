//Cracked by Kafei
static int luck;
void set_killer_name(string kind)
{
	switch(kind){
	case "�䵱��":
		set_name("�ɹ�����", ({ "menggu dazi", "menggu", "dazi" }) );
	    set("long", "�������θߴ����ͣ��������࣬һ���ɹž��ٴ�硣\n");
		break;
	case "������":
		set_name("ħ�̵���", ({ "mojiang dizi", "mojiang", "dizi" }) );
	    set("long", "����ͷϵ�غ�ɫ�������������磬�ݳ������ϴ��ż��ֹ����Ц�ݡ�\n"
			"������ݳ�����ɫ�������ϣ������ż��ֹ����ͼ���������¶�����滹�м�\n"
			"�������˺�,��������а֮����\n");
		break;

	case "ȫ���":
		set_name("а�ɵ���", ({ "xiepai dizi", "xiepai", "dizi" }) );
	    set("long", "����ͷϵ�غ�ɫ�������������磬�ݳ������ϴ��ż��ֹ����Ц�ݡ�\n"
			"������ݳ�����ɫ�������ϣ������ż��ֹ����ͼ���������¶�����滹�м�\n"
			"�������˺�,��������а֮����\n");
		break;
	case "��ɽ":
	case	"�һ���":
	case	"ؤ��":
	case	"����μ�":
	case	"������":
	case	"ѩɽ��":
		set_name("ǿ��", ({ "qiang dao", "qiang", "dao" }) );
	    set("long", "���˰ײ��������������⣬����ͭ����һ���׺�ģ����\n"
			"�����θߴ󣬳���¶�ۣ���ë���ţ���ɫ������ϵ���䡣վ�ڴ˴���ɢ����һ��\n"
			"���˵�ɱ����\n");
		break;
	case "������ ":
	case	"����ɽ":
		set_name("������ʿ", ({ "jianghu xiashi", "jianghu", "xiashi" }) );
	    set("long", "���Ǹ����߽�����������ʿ��һ��������˫Ŀ�������񣬿����ڼҹ���\n"
			"��Ϊ����������Ŀ��࣬һ�������ѩ���˵�һվ��ɢ����һ�ɺ�Ȼ������\n");
		break;
		    default:
		set_name("ǿ��", ({ "qiang dao", "qiang", "dao" }) );
	    set("long", "���˰ײ��������������⣬����ͭ����һ���׺�ģ����\n"
			"�����θߴ󣬳���¶�ۣ���ë���ţ���ɫ������ϵ���䡣վ�ڴ˴���ɢ����һ��\n"
			"���˵�ɱ����\n");
		break;
	}
	return ;

}
void Set_Npcattrib(int Basic_Attrib,int Random_var,
				   int Maxqi,int Random_Maxqi,
				   int Maxjing,int Random_Maxjing,
				   int Maxjingli,int Random_Maxjingli,
				   int Maxneili,int Random_Maxneili,
				   int Exp,int Random_Exp)
				  				  
{
	int Mneili=Maxneili+random(Random_Maxneili),max;
	set("str", Basic_Attrib+random(Random_var));
	set("int", Basic_Attrib+random(Random_var));
	set("con", Basic_Attrib+random(Random_var));
	set("dex", Basic_Attrib+random(Random_var));

	set("max_qi", Maxqi+random(Random_Maxqi));
	set("max_jing", Maxjing+random(Random_Maxjing));
	set("max_jingli", Maxjingli+random(Random_Maxjingli));
	set("max_neili", Mneili);
	set("combat_exp", Exp+random(Random_Exp));
	
	  max =query("max_jing");
	  set("eff_jing",max);
	  set("jing",max);
	  max = query("max_qi");
	  set("eff_qi",max);
	  set("qi",max);
	  max =query("max_neili");
	  set("eff_neili",max);
	  set("neili",max);
	  max = query("max_jingli");
	  set("eff_jingli",max);
	  set("jingli",max);
	return;
}

void Set_Npcskills(int Basic_skill,int Random_skill,mapping S_skills)
{
	int i,jiali ;
	mixed S_name;
	
	if(i=sizeof(S_skills))
	{
		S_name=keys(S_skills);
		for(i=0;i<sizeof(S_name);i++)
		{
			set_skill(S_name[i], Basic_skill+random(Random_skill) );
			set_skill(S_skills[S_name[i]], Basic_skill+random(Random_skill) );
			map_skill(S_name[i],S_skills[S_name[i]]);
		}
	}
	set_skill("literate", Basic_skill+random(Random_skill));
	jiali=(Basic_skill+Basic_skill/2)/2;
	jiali=jiali-jiali*luck/20;
	set("jiali",jiali);
	return;
}
void skills_setup(string kind,int skill,int r_s)
{
	int ran;
	mapping S_skills= ([ ]);
	switch(kind){
	case "�䵱��":
	case "��ɽ��":
	case "������":
	case "������":
	case "����μ�":
	case "ȫ���":
		{
			ran=random(4);
			
			switch(ran){
			case 0://xingxiu
				S_skills["dodge"]="luoying-shenfa";
					S_skills["parry"]="luoying-shenjian";
					S_skills["force"]="bitao-xuangong";
					S_skills["strike"]="luoying-shenjian";
					S_skills["kick"]="xuanfeng-saoye";
				Set_Npcskills(skill,r_s,S_skills);
				prepare_skill("strike","luoying-shenjian");
				prepare_skill("kick","xuanfeng-saoye");
				 set("chat_msg_combat", ({
							(: perform_action, "strike.kuangfeng" :)
								
					}));
				 
				 set("jiali",query("jiali")/5);
				
/*				S_skills["dodge"]="feixing-shu";
				S_skills["parry"]="chousui-zhang";
				S_skills["force"]="huagong-dafa";
				S_skills["claw"]="sanyin-zhua";
				S_skills["strike"]="chousui-zhang";
			
			Set_Npcskills(skill,r_s,S_skills);

			prepare_skill("claw","sanyin-zhua");
			prepare_skill("strike","chousui-zhang");
			set("chat_msg_combat", ({
						(: perform_action, "claw.sanyin" :)

				}));
			set("jiali",query("jiali")/3);
*/
			break;
			case 1://baituo
				S_skills["dodge"]="chanchubu";
				S_skills["parry"]="hamagong";
				S_skills["force"]="hamagong";
				S_skills["strike"]="hamagong";
				S_skills["cuff"]="lingshe-quan";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","hamagong");
			set("chat_msg_combat", ({
						(: perform_action, "strike.puji" :)
				}));
			set("jiali",query("jiali")/5);
			break;		
			case 2://xueshan
				S_skills["dodge"]="shenkongxing";
				S_skills["parry"]="huoyan-dao";
				S_skills["force"]="longxiang-banruo";
				S_skills["strike"]="huoyan-dao";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","huoyan-dao");
			set("chat_msg_combat", ({
						(: perform_action, "strike.fen" :)
				}));

			
			set("jiali",query("jiali")/5);
			break;		
			case 3://gaibang
				S_skills["dodge"]="xiaoyaoyou";
				S_skills["parry"]="xianglong-zhang";
				S_skills["force"]="huntian-qigong";
				S_skills["strike"]="xianglong-zhang";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","xianglong-zhang");
				set("chat_msg_combat", ({
						(: perform_action, "strike.leiting" :),
							(: perform_action, "strike.sanhui" :)
				}));
				
				set("jiali",query("jiali")/5);

			break;		
			case 4://taohua
					S_skills["dodge"]="luoying-shenfa";
					S_skills["parry"]="luoying-shenjian";
					S_skills["force"]="bitao-xuangong";
					S_skills["strike"]="luoying-shenjian";
					S_skills["kick"]="xuanfeng-saoye";
				Set_Npcskills(skill,r_s,S_skills);
				prepare_skill("strike","luoying-shenjian");
				prepare_skill("kick","xuanfeng-saoye");
				 set("chat_msg_combat", ({
							(: perform_action, "strike.kuangfeng" :)
								
					}));
				 set("jiali",query("jiali")/5);
			break;		
			}
		
		}
		break;

		case "������":
		case "����ɽ":
		case "ؤ��":
		case "ѩɽ��":
		case "�һ���":
			{
				ran=random(5);
				switch(ran){
				case 0://wudang
					S_skills["dodge"]="tiyunzong";
					S_skills["parry"]="taiji-quan";
					S_skills["force"]="taiji-shengong";
					S_skills["cuff"]="taiji-quan";
				Set_Npcskills(skill,r_s,S_skills);
				prepare_skill("cuff","taiji-quan");
				 set("chat_msg_combat", ({
							(: perform_action, "cuff.luanhuan" :),
								(: perform_action, "cuff.nian" :)
					}));
				 set("jiali",query("jiali")/5);
					break;
				case 1://huashan
					S_skills["dodge"]="huashan-shenfa";
					S_skills["parry"]="pishi-poyu";
					S_skills["force"]="zixia-gong";
					S_skills["strike"]="hunyuan-zhang";
					S_skills["cuff"]="pishi-poyu";
				Set_Npcskills(skill,r_s,S_skills);
				prepare_skill("cuff","pishi-poyu");
				prepare_skill("strike","hunyuan-zhang");
				set("chat_msg_combat", ({
							(: perform_action, "strike.leidong" :)
//								(: perform_action, "strike.wuji" :)
								
					}));
				set("jiali",query("jiali")/10);
				break;
				case 2://emei
					S_skills["dodge"]="zhutian-bu";
					S_skills["parry"]="tiangang-zhi";
					S_skills["force"]="linji-zhuang";
					S_skills["strike"]="jinding-zhang";
					S_skills["finger"]="tiangang-zhi";
				Set_Npcskills(skill,r_s,S_skills);
				prepare_skill("finger","tiangang-zhi");
				prepare_skill("strike","jinding-zhang");
					set("chat_msg_combat", ({
							(: perform_action, "strike.puzhao" :)

					}));
					set("jiali",query("jiali")/5);
				break;
				case 3://dali
					S_skills["dodge"]="duanshi-shenfa";
					S_skills["parry"]="yiyang-zhi";
					S_skills["force"]="kurong-changong";
					S_skills["strike"]="qingyan-zhang";
					S_skills["finger"]="yiyang-zhi";
				Set_Npcskills(skill,r_s,S_skills);
				prepare_skill("finger","yiyang-zhi");

					set("chat_msg_combat", ({
							(: perform_action, "finger.qiankun" :)

					}));
					set("jiali",query("jiali")/7);
				break;
				case 4://quanzhen
					S_skills["dodge"]="jinyangong";
					S_skills["parry"]="sanhua-juding";
					S_skills["force"]="xiantian-gong";
					S_skills["strike"]="sanhua-juding";
					S_skills["cuff"]="chunyang-quan";
				Set_Npcskills(skill,r_s,S_skills);
				prepare_skill("cuff","chunyang-quan");
				prepare_skill("strike","sanhua-juding");

					set("chat_msg_combat", ({
							//(: perform_action, "cuff.lianhuan" :),
								(: perform_action, "strike.sanhua" :)


					}));
					set("jiali",query("jiali")/7);
				break;
				case 5://shaolin
					S_skills["dodge"]="shaolin-shenfa";
					S_skills["parry"]="yizhi-chan";
					S_skills["force"]="hunyuan-yiqi";
					S_skills["strike"]="banruo-zhang";
					S_skills["finger"]="yizhi-chan";
				Set_Npcskills(skill,r_s,S_skills);
				prepare_skill("finger","yizhi-chan");
				prepare_skill("strike","banruo-zhang");

					set("chat_msg_combat", ({
							(: perform_action, "finger.jingmo" :),
								(: perform_action, "strike.san" :)

					}));
					set("jiali",query("jiali")/5);
				break;


			}
			break;
			}
			default:
				{
				S_skills["dodge"]="xiaoyaoyou";
				S_skills["parry"]="xianglong-zhang";
				S_skills["force"]="huntian-qigong";
				S_skills["strike"]="xianglong-zhang";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","xianglong-zhang");
				set("chat_msg_combat", ({
						(: perform_action, "strike.leiting" :),
							(: perform_action, "strike.sanhui" :)
				}));
				set("jiali",query("jiali")/5);
				break;
				}



			}
}
