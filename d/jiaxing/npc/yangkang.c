//yangkang.c
//by zhuifeng 2010

inherit NPC;
string ask_me();
string ask_me2();
#include <ansi.h>;

void create()
{
        set_name("�", ({"yang kang", "kang", "yang"}));
        set("gender", "����");
        set("title", HIC "ȫ��̵���������"NOR );
        set("age", 24);
        set("class", "fighter");
        set("long",
                "���������տ�����ĸ��ϧ�������պ��Һ󣬳���С���ӣ�
̰ͼ�����������ġ�\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 26);
        set("int", 25);
        set("con", 25);
        set("dex", 26);
        set("per", 28);
        set("kar", 30);
        set("pur", 15);

        set("chat_chance_combat", 350);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "wuqi" :),
                (: exert_function, "ding" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "claw.jiuyin" :),
        }));

        set("qi", 100000);
        set("max_qi", 10000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 100000);
        set("eff_jingli",10000);
        set("jingli",10000);
        set("max_neili", 100000);
        set("jiali", 200);
        set("quest/jiuyin2/pass",1);
        set("quest/���Ӣ�۴�/yangjiaqiang/pass",1);

        set("combat_exp", 4300000);

        set_skill("force", 350);
        set_skill("xiantian-gong", 350);
        set_skill("sword", 350);
        set_skill("quanzhen-jianfa", 350);
        set_skill("dodge", 350);
        set_skill("jinyan-gong", 350);
        set_skill("yangjia-qiang", 120);
        set_skill("spear", 120);
        set_skill("parry", 350);
        set_skill("strike", 350);
        set_skill("haotian-zhang", 350);
        set_skill("claw",350);
        set_skill("jiuyin-baiguzhua", 320);
        set_skill("literate", 200);
        set_skill("taoism", 50);
        set_skill("yinlong-bian", 180);
        set_skill("cuixin-zhang", 200);
        set_skill("whip",200);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
         map_skill("spear", "yangjia-qiang");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "cuixin-zhang");
        map_skill("claw", "jiuyin-baiguzhua");
        map_skill("whip","yinlong-bian");
        prepare_skill("claw", "jiuyin-baiguzhua");
        
        set("inquiry", ([
    "��Х��" : "�Ҳ���ʶ��",
    "������" : "�Ҳ���ʶ��",
    "����" : "�Ҳ���ʶ��",
    "��Ƽ" : "�Ҳ���ʶ��",
    "��ϧ��" : "�������",
    "�����" : "�����ҵ�Ů�ˣ���������ʲô��",
    "����" : "˭������",
    "���պ���" : "�����Ҹ���ʲô���飿",
    "�𴦻�" : "������ʦ��",
    "÷����" : "������ʦ��",
    "ŷ����" : "��С��������ε�Ϸ��ȣ��Ҳ���Ź����ģ�",
    "���տ�" : (: ask_me :),
    "�" : (: ask_me2 :),


	]));


  set("chat_chance", 5);
 set("chat_msg", ({
       "˭Ҳ���������뿪�Ҹ�����������ÿ��Ҫ���뿪���Ҿ��ȼ�װ��Ӧ�����ٺ٣�Ů�����ƭ��\n",
       "ʦ��Ҫ�������˺������ֱ��䣬����������λ��Һ��£������Ҫ�����ÿ����ߡ��ߣ�\n",
 }) );
        create_family("ȫ���", 3, "����");

        setup();

        carry_object("/d/fuzhou/npc/obj/txs")->wield();
        carry_object("/clone/armor/jinduan")->wear();
}

string ask_me()
{
        object me,ob;
	ob=this_player();
	me=this_object();
        command("unwield shan"); 
	me->set_name("���տ�", ({ "wanyan kang", "kang","wanyan"}) );
	me->set("title",HIY"����С��ү"NOR);
	return "�ұ��Ǵ���С��ү������ʲô���飡";
}

string ask_me2()
{
        object me,ob;
	ob=this_player();
	me=this_object();
  command("wield shan");
	me->set_name("�", ({ "yang kang", "kang","yang"}) );
	me->set("title",HIC"ȫ��̵���������"NOR);
	return "���±�����������Һ��£�";
}

