// attribute.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// Last Modified By Ciwei@SJ

#include <dbase.h>
#include <skill.h>

int sld_btyjw();

varargs int query_str(int post)
{
	int improve;
	
	improve = query_skill("claw", 1) / 10;
	improve = MAX(improve,query_skill("cuff", 1) / 10);
	improve = MAX(improve,query_skill("finger", 1) / 10);
	improve = MAX(improve,query_skill("hand", 1) / 10);
	improve = MAX(improve,query_skill("strike", 1) / 10);
	improve = MAX(improve,query_skill("leg", 1) / 10);
	improve = MAX(improve,query_skill("unarmed", 1) / 10);
	improve +=sld_btyjw();
		
	return query("str") + (post?0:query_temp("apply/strength")) + improve;
}

varargs int query_int(int post)
{
	int improve=query_skill("literate", 1) / 10;
	improve +=sld_btyjw();
	return query("int") + (post?0:query_temp("apply/intelligence")) +  improve;
}

varargs int query_con(int post)
{
	int improve=query_skill("force", 1) / 10;
	improve +=sld_btyjw();
	return query("con") + (post?0:query_temp("apply/constitution")) + improve;
}

varargs int query_dex(int post)
{
	int improve= query_skill("dodge", 1) / 10;
	improve +=sld_btyjw();
	return query("dex") + (post?0:query_temp("apply/dexerity")) +	// should be dexterity, damn it. YUJ@SJ
		improve;
}

varargs int query_kar(int post)
{
	return query("kar") + (post?0:query_temp("apply/karma"));
}

varargs int query_per(int post)
{
	return query("per") + (post?0:query_temp("apply/personality"))
		+ (query("gender") == "����"?0:query_skill("beauty", 1) / 20)
		- query("age")/10 + 2 // 20 �Ժ�ſ�ʼ��per, ���Լ�2.
		- (query_skill("qianzhu-wandushou", 1) < 60?0:query_skill("qianzhu-wandushou", 1)/ 15);
}

int sld_btyjw()
{
	if(!query("quest_kill/btyao")) return 0;
	if(!query("quest_kill/fz_month")) set("quest_kill/fz_month",1+random(12));
	
	//�������� �·ݷ��� ���ǸճԵ� �����Ѿ���������
	if(query("quest_kill/fz_month")==query("month")
	&& query("age")!=query("quest_kill/bt_year")
	&& query("age")!=query("quest_kill/fz_year") )
	{
		set("quest_kill/now_month",query("quest_kill/fz_month"));
		set("quest_kill/fz_month",1+random(12));
		set("quest_kill/fz_year",query("age"));
		add("quest_kill/fazuo",1);
		message("channel","\n\n��е�С��һ���ʹ�������Ǳ�̥�׽���Ķ������ˡ�\n",this_object());
		//return sld_btyjw();
	}
	if(query("quest_kill/fazuo"))
		return -query("quest_kill/fazuo");
	return 1;
}
