// huoji. ҩ�̻��
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

int ask_yjw();
void create()
{
        set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
        set("str", 20);
        set("gender", "����");
        set("age", 18);
        set("long", "һ��µæ��С��ơ�\n");
        set("combat_exp", 250);
        set("attitude", "friendly");
        set("vendor_goods", ({
        (["name":MEDICINE_D("jinchuang"),"number":25]),
        (["name":"/clone/medicine/m-book1","number":5]),
        (["name":"/clone/medicine/jingmai/jingmai-book1","number":1]),
        (["name":MEDICINE_D("yangjing"),"number": 20]),
        (["name":MEDICINE_D("jys"),"number": 100]),
        }));
        
	set("inquiry", ([
		"����" : (: ask_yjw :),
		"yuji wan" : (: ask_yjw :),
		])); 
        setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int ask_yjw()
{
	object ob, me = this_player();
	
	if (present("yuji wan", me))
        {	
        	command("say �㲻���Ѿ�����ô��");
                return 1; 
	}
	
	if (me->query("max_neili")<100 || me->query("eff_jingli")<200)
	{
		ob = new(MEDICINE_D("neili/yujiwan"));
		ob->set("owner", me->query("id"));
		ob->move(me);
		command("say С�ĵ�,��Ҫ�ٵ���!");
		message_vision("$N�ݸ�$nһ��"+HIW+"����"+NOR+"��\n", this_object(), me); 
		return 1;
	}
	else
	{
		command("say ���ҳ�ҩ��������!");
		return 1;
	}
}

