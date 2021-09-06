// zheluoxing.c ������
// by iceland

#include <ansi.h>
inherit NPC;

string ask_xueliandan();

void create()
{
        set_name("������", ({ "zheluo xing", "zheluoxing","zheluo","xing" }));
        set("long",@LONG
������еȣ�ͷ���ͺ���ϡϡ�����ĳɿݻ�ɫ��һ˫üë�´����Եó�ü������
���Ǹ�������ˣ���Ϊ��Ľ�����µķ𷨺��书�����Ժ�ʦ���������С�
LONG
        );
        set("title", HIY "�����µ�ʮ��������" NOR);
        set("gender", "����");
	set("class", "huanxi");
        set("age", 34);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 28);
        set("int", 15);
        set("con", 28);
        set("dex", 30);
        set("max_qi", 1000);
        set("eff_jing", 400);
	set("max_jing",400);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 40);
        set("combat_exp", 350000);
        set("score", 140000);
	set("unique", 1);

        set_skill("huanxi-chan", 100);
        set_skill("literate", 80);
        set_skill("force", 100);
        set_skill("longxiang-boruo", 100);
        set_skill("dodge", 100);
        set_skill("yuxue-dunxing", 100);
        set_skill("hand", 100);
        set_skill("dashou-yin", 100);
        set_skill("staff", 100);
        set_skill("wushang-dali", 100);
        set_skill("parry", 100 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "wushang-dali");
        map_skill("staff", "wushang-dali");

        prepare_skill("hand","dashou-yin");

        create_family("������", 12, "����");
        set("class", "huanxi");

        set("inquiry", ([
                "ѩ����" : (: ask_xueliandan :),
        ]));
        set("xuelian_count", 1 + random(4));
        set("chat_chance", 1);
        set("chat_msg", ({
		"�����ǹ�ǻ�ֵ��ı�Թ��������������Ҫ�ɻѧ�����书��������ȥ�����¿�������\n",
        }) );
        setup();
        carry_object(__DIR__"obj/gongde-jiasha")->wear();
        carry_object(BINGQI_D("jingangzuan"))->wield();      

        add_money("gold",1);
}
string ask_xueliandan()
{
	mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="������")
                return RANK_D->query_respect(this_player()) + 
                "���Ǳ��ɵ��ӣ���ô�Ա�����ҩҲ��������ѽ��";

        if ( (int)this_player()->query_condition("neili_drug" ) > 0 )
                return RANK_D->query_respect(this_player()) + 
                "����������ǲ��ǸոճԹ�����ҩ���Ʋ��ף����Ҳ���˷ѣ�һ�������ɡ�";

        if (  present("xuelian dan", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "�������ϲ����п�ҩ������������Ҫ�ˣ�����̰�����ᣡ";

        if ( (int)this_player()->query("max_jingli") < 200 )
                return RANK_D->query_respect(this_player()) +"����������ѩ���������к����档";

        if (query("xuelian_count") < 1)
                return RANK_D->query_respect(this_player()) +"���Ĳ��ɣ�������Ҳû���ˡ�";

        ob = new(MEDICINE_D("xueliandan"));
        ob->move(this_player());
        add("xuelian_count", -1);

        message_vision("$N���һ��ѩ������\n",this_player());
        return "�ðɣ���ס����ҩ����ʵ�ڲ��ף�����Ҫ�˷��ˡ�";
}
