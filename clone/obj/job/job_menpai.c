//Cracked by Kafei
//wzfeng@xkx 2000 6
// job_menpai.c  ���ɿ��ƺ����ļ���
#include <ansi.h>
inherit F_SAVE;
inherit ITEM;
#include "lpc_math.h"
mapping family;
mapping *familys;//�������ɵ�����
mapping family_assess_number;


mapping *query_familys()
{
	return familys;
}
void create()
{
	 set_name("���ɿ�����",  ({"menpai_system"}));
	seteuid(getuid());
}
string query_save_file()
{
        return DATA_DIR + "job_system/menpai"; 
}
//Set a new family data in familys.
void set_default()
{
	familys=({});

}
void set_familys(mapping family)
{
        if( !pointerp(familys) )
        {
         familys = ({ family });
        }
        else familys += ({ family });

}

//����������Ӣ��ת�� string name,Ҫת�������ƣ�int mode ת����ʽ 1=���ĵ�Ӣ�� 2=Ӣ�ʵ�����
string con_name(string name,int mode)
{
	string con_name;
	if(mode==1)
	{
		switch(name) {
		case "�䵱��": con_name = "wudang"; break;
		case "������": con_name = "xingxiu"; break;
		case "��ɽ��": con_name = "huashan"; break;
		case "�һ���": con_name = "taohua"; break;
		case "ؤ��": con_name = "gaibang"; break;
		case "������": con_name = "emei"; break;
		case "����ɽ": con_name = "baituo"; break;
		case "ȫ���": con_name = "quanzhen"; break;
		case "ѩɽ��": con_name = "xueshan"; break;
		case "����μ�": con_name = "dali"; break;
		case "������": con_name = "shaolin"; break;

		default:
				return ("����ת������\n");

		}
		return con_name;
	}
	if(mode==2)
		{
		switch(name) {
		case "wudang": con_name = "�䵱��"; break;
		case "xingxiu": con_name = "������"; break;
		case "huashan": con_name = "��ɽ��"; break;
		case "taohua": con_name = "�һ���"; break;
		case "gaibang": con_name = "ؤ��"; break;
		case "emei": con_name = "������"; break;
		case "baituo": con_name = "����ɽ"; break;
		case "quanzhen": con_name = "ȫ���"; break;
		case "xueshan": con_name = "ѩɽ��"; break;
		case "dali": con_name = "����μ�"; break;
		case "shaolin": con_name = "������"; break;

			default:
				return ("Ӣ��-����������ת������\n");

		}
		return con_name;
	}

	return ("mode error3\n");
}
int query_luck(string name)
{
	int i;
		for(i=0;i<sizeof(familys);i++)
		if(familys[i]["family_name"]==name)
			return familys[i]["family_luck"];
		return 0;


}
int do_set_luck(string name,int luck)
{
	int i;
		for(i=0;i<sizeof(familys);i++)
		if(con_name(familys[i]["family_name"],1)==name)
		{
			familys[i]["family_luck"]=luck;
			save();
			return 1;
		}
		return notify_fail ("set luck error��\n");
}
int do_set_assess_num(string name,int num)
{
	int i;
		for(i=0;i<sizeof(familys);i++)
		if(con_name(familys[i]["family_name"],1)==name)
		{
			familys[i]["family_assess_num"]=num;
			save();
			return 1;
		}
		return notify_fail ("set family_assess_num error��\n");
}

int do_set_rate(string name,int luck)
{
	int i;
		for(i=0;i<sizeof(familys);i++)
		if(con_name(familys[i]["family_name"],1)==name)
		{
			familys[i]["family_rate"]=luck;
			save();
			return 1;
		}
		return notify_fail ("set rate error��\n");
}

int do_set_money(string name,int luck)
{
	int i;
		for(i=0;i<sizeof(familys);i++)
		if(con_name(familys[i]["family_name"],1)==name)
		{
			familys[i]["family_money"]=luck;
			save();
			return 1;
		}
		return notify_fail ("set money error��\n");
}

int have_menpai(string name)
{
	int i;
	for(i=0;i<sizeof(familys);i++)
	{
		if(con_name(familys[i]["family_name"],1)==name)
		{
			return 1;
		}
	}
		return 0;
}

//num�޸���Ӧ��strategy
int have_strategy(string menpai,string strategy,int num)
{
	int i,j;
	string *strategy_name;

	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==con_name(menpai,2))
		{

			if(!sizeof(familys[i]["family_strategy"]))
				return notify_fail ("�������û���ƶ����ԡ�\n");
			else
			{

				strategy_name=keys(familys[i]["family_strategy"]);
				for(j=0;j<sizeof(familys[i]["family_strategy"]);j++)
				{
					if(strategy_name[j]==strategy)
						{
						if(num)
						{
							familys[i]["family_strategy"][strategy_name[j]]=num;
							save();
						}

						return familys[i]["family_strategy"][strategy_name[j]];
						}
				}
				
			}
		return notify_fail ("�������û���ƶ����ֲ��ԡ�\n");
		}

	}
		return notify_fail ("û��������ɡ�\n");

}
//num�޸���Ӧ��area power
int have_power(string menpai,string area,int num)
{
	int i,j;
	string *area_name;
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==con_name(menpai,2))
		{
			if(!sizeof(familys[i]["family_power"]))
				return notify_fail ("�������û���������Χ�ڵ�������\n");
			else
			{
				area_name=keys(familys[i]["family_power"]);
				for(j=0;j<sizeof(familys[i]["family_power"]);j++)
				{
					if(area_name[j]==area)
						{
						if(num)
						{
							familys[i]["family_power"][area_name[j]]=num;
							save();
						}

						return familys[i]["family_power"][area_name[j]];
						}
				}
				
			}
		return notify_fail ("�������û�����������������\n");
		}

	}
		return notify_fail ("û��������ɡ�\n");

}



//Add a new family data. 
//parameter explain:
//string family_name  ���ɵ�����
//mapping strategy      ���ɷ�չ����(��һ��mixed����ʾ�����п�����ϸ˵�����Ը��ֲ���)
//int luck			  ��������ֵ(Ӱ����������͸������������Խ���ʾ������Խ����)
//int money           ���ɵĲ�����ֵ(Ӱ�����ɲ��Ժ����ɳ�Ա��ٺ»)
//mapping power         ���ɵ�����(Ӱ��������Ϸ����������ϵͳ)


int add_orgdata(string family_name,mapping strategy,int luck,int money,int rate,mapping power,int assess_num)
{
	int i,j;

	if(!sizeof(familys))
	{
			family = ([
    		"family_name":family_name,
			"family_strategy":strategy,
			"family_luck":luck,
			"family_money":money,
			"family_power":power,
			"family_rate":rate,
			"family_assess_num":assess_num,
      
        ]);
			write(family_name+"������ɹ�����һ������)��\n");
			set_familys(family);
			save();
			return 1;

	}

	j=sizeof(familys);
	
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==family_name)
		{
			//printf("%s\n",familys[i]["family_name"]);
			return notify_fail ("�Ѿ�����������ˣ���ʹ��change_orgdata���޸ġ�\n");
		}
			family = ([
    				"family_name":family_name,
					"family_strategy":strategy,
					"family_luck":luck,
					"family_money":money,
					"family_power":power,
					"family_rate":rate,
					"family_assess_num":assess_num,
      
				]);
		write(family_name+"������ӳɹ���\n");
		set_familys(family);
		save();
		return 1;

		}
	
	
	return 1;

}
// change familys data.
int change_orgdata(string family_name,mapping strategy,int luck,int money,int rate,mapping power,int assess_num)
{
	int i,j;

	if(!sizeof(familys))
		return 0;
	j=sizeof(familys);
	
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==family_name)
		{
			
			familys[i] = ([
			"family_name":family_name,
			"family_strategy":strategy,
			"family_luck":luck,
			"family_money":money,
			"family_power":power,
			"family_rate":rate,
			"family_assess_num":assess_num,
      
        ]);
			
			save();
			return 1;
		}
	}
		return notify_fail ("û����������ˣ���ʹ��add_orgdata�������µ��������ݡ�\n");

}
mapping query_assess_basenum(string family)
{
	mapping family_map;
	family_map=get_mapping(family,"family_name",familys);
	return family_map;
}
//query_orgdata
int query_full_menpaidata(string menpai_name)
{
	int i,j;
	string *strategy_name;
	if(!sizeof(familys))
		return notify_fail ("����û���κν���������Ϣ����ʹ��setorg_default������ȱʡ������\n");
		
	
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==con_name(menpai_name,2))
		{
			write(HIC+con_name(menpai_name,2)+"��ϸ�б�:\n"NOR);
			write("�������˵���\t\t"+familys[i]["family_luck"]+"\n"NOR);
			write("���ɽ�Ǯϵ��\t\t"+familys[i]["family_money"]+"\n"NOR);
			write("���ɵ���������\t\t"+familys[i]["family_assess_num"]+"\n"NOR);
			if(!sizeof(familys[i]["family_strategy"]))
				write("���ɲ�����\n"NOR);
			else
			{
				strategy_name=keys(familys[i]["family_strategy"]);
				write("���ɲ�����ϸ��\n");
				for(j=0;j<sizeof(familys[i]["family_strategy"]);j++)
					printf("\t%-20s\t%d\n",strategy_name[j],familys[i]["family_strategy"][strategy_name[j]]);
			}

			if(!sizeof(familys[i]["family_power"]))
				write("����������\n"NOR);
			else
			{
				strategy_name=keys(familys[i]["family_power"]);
				write("����������ϸ��\n");
				for(j=0;j<sizeof(familys[i]["family_power"]);j++)
				printf("\t%-20s\t%d\n",strategy_name[j],familys[i]["family_power"][strategy_name[j]]);
			}


		}
	}

	return 1;

}
int query_strategy_list(int mode)
{
	
	int i;
	if(!sizeof(familys))
		return notify_fail ("����û���κν���������Ϣ����ʹ��setorg_default������ȱʡ������\n");
		
	write(HIC"Ŀǰ�������ɵ���Ҫ����Ϊ:\n"NOR);
	for(i=0;i<sizeof(familys);i++)
	{
		write(familys[i]["family_name"]+"\n");
	}

	return 1;
}

int query_menpai_list()
{
	
	int i;
	if(!sizeof(familys))
		return notify_fail ("����û���κν���������Ϣ����ʹ��setorg_default������ȱʡ������\n");
		
	write(HIC"Ŀǰ���ֻþ����Ƶ�������:\n"NOR);
	for(i=0;i<sizeof(familys);i++)
	{
		write(HIW+familys[i]["family_name"]+"\n"NOR);
	}

	return 1;
}

int query_luck_list()
{
	
	int i;
	if(!sizeof(familys))
		return notify_fail ("����û���κν���������Ϣ����ʹ��setorg_default������ȱʡ������\n");
		
	write(HIC"Ŀǰ�������ɵ����˵���Ϊ:\n"NOR);
	for(i=0;i<sizeof(familys);i++)
	{
		write(familys[i]["family_name"]+"\t\t");
		write(familys[i]["family_luck"]+"\n");
	}

	return 1;
}
int query_money_list()
{
	
	int i;
	if(!sizeof(familys))
		return notify_fail ("����û���κν���������Ϣ����ʹ��setorg_default������ȱʡ������\n");
		
	write(HIC"Ŀǰ�������ɵĽ�Ǯ����ϵ��Ϊ:\n"NOR);
	for(i=0;i<sizeof(familys);i++)
	{
		write(familys[i]["family_name"]+"\t\t");
		write("�ٷ�֮"+familys[i]["family_money"]+"\n");
	}

	return 1;
}

string random_get_menpai_strategy(string menpai)
{
	int i,j,strategy_random,strategy_sum;
	string *strategy_name,random_strategy_name;
	strategy_random=1+random(99);
	if(!(i=sizeof(familys)))
		return "error";
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==menpai)
		{
			

			if(!sizeof(familys[i]["family_strategy"]))
				return ("�������û���ƶ����ԡ�\n");
			else
			{

				strategy_name=keys(familys[i]["family_strategy"]);
				//printf("��������Ĳ�����ֵ=%d\n",strategy_random);
				for(j=0;j<sizeof(familys[i]["family_strategy"]);j++)
					{
					strategy_sum +=familys[i]["family_strategy"][strategy_name[j]];
					if(strategy_random<strategy_sum)
					return strategy_name[j];
				}
			}
		return ("�������û���ƶ����ֲ��ԡ�\n");
		}
	}
		return ("û���������(restore())��\n");
}

string random_get_menpai_areapower(string menpai)
{
	int i,j,menpai_area_power_sum,power_sum,power_random;
	string *area_name;
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==menpai)
		{
			if(!sizeof(familys[i]["family_power"]))
				return ("�������û������Χ�ڵ�������\n");
			else
			{
				area_name=keys(familys[i]["family_power"]);
				
				for(j=0;j<sizeof(familys[i]["family_power"]);j++)
				{
					menpai_area_power_sum +=familys[i]["family_power"][area_name[j]];
				}
				//printf("�����������ܺ�=%d\n",menpai_area_power_sum);
				
				power_random=1+random(menpai_area_power_sum-1);
				//printf("�漴��������������ֵ=%d\n",power_random);
				for(j=0;j<sizeof(familys[i]["family_power"]);j++)
				{
					power_sum +=familys[i]["family_power"][area_name[j]];
					if(power_random<power_sum)
					return area_name[j];
				}
			}
		return ("�������û�����������������\n");
		}
	}
		return ("û��������ɡ�\n");
}
string get_random_menpai()
{
		int i,j,all_num,random_num,temp_num;
	string menpai;
	if(!(i=sizeof(familys)))
		return "error";
	for(j=0;j<i;j++)
		all_num+=familys[j]["family_rate"];
	//printf("���ɱ��ʵ��ܺ�Ϊ:\t%d\n",all_num);
	random_num=1+random(all_num-1);
	//printf("�漴���������ɱ���ֵ=%d\n",random_num);
	for(j=0;j<sizeof(familys);j++)
		{
		
		//printf("%s�ı���Ϊ:\t%d\n",familys[j]["family_name"],familys[j]["family_rate"]);
		temp_num +=familys[j]["family_rate"];
		if(random_num<temp_num)
		{
			return familys[j]["family_name"];
		}
		}


	
return ("û��������ɡ�\n");

}
int query_rate_list()
{
	
	int i;
	if(!sizeof(familys))
		return notify_fail ("����û���κν���������Ϣ����ʹ��setorg_default������ȱʡ������\n");
		
	write(HIC"Ŀǰ�����ɲ�������ı���Ϊ:\n"NOR);
	for(i=0;i<sizeof(familys);i++)
	{
		write(HIW+familys[i]["family_name"]+":\t\t"NOR);
		write(HIW+familys[i]["family_rate"]+"\n"NOR);
	}

	return 1;
}


