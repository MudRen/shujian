// cool980310
// ������
// cool980724
// Modify By River 98/12
inherit NPC;

void create()
{
        set_name("������", ({ "duan yanqing", "duan","yanqing"}) );
        set("nickname", "�����ӯ");
	set("title", "�Ĵ����");
        set("gender", "����" );
        set("age", 52);
        set("str", 26);
        set("con", 23);
        set("dex", 5);
        set("int", 25);
        set("per", 10);
   	set("attitude", "friendly");

        set("max_qi", 7000);
        set("max_jing", 3000);
        set("eff_jingli", 3000);
        set("neili", 10000);
        set("qi", 7000);
        set("max_neili", 10000);
        set("jiali", 100);         
        
        set("long","�����Ǹ����ߣ����봹�أ���Ŀ��ڡ�\n");
        set("combat_exp", 2100000);
       set("env/һ��ָ","����");
        set("shen", -20000);

        set("chat_chance_combat", 30);
        set("chat_msg_combat",({ 
          (: perform_action, "finger.sandie" :),
        }));

        set_skill("parry", 210);
        set_skill("dodge", 160);
        set_skill("force", 210);
        set_skill("finger", 160);
        set_skill("buddhism", 100);
        set_skill("literate", 120);
        set_skill("sword", 130);
        set_skill("duanjia-jianfa", 120);
        set_skill("qiantian-yiyang", 210);
        set_skill("yiyang-zhi", 210);
        set_skill("tianlong-xiang", 50);
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        map_skill("force", "qiantian-yiyang");
        prepare_skill("finger","yiyang-zhi");

        set("inquiry", ([
           "����" : "�ٺ٣������ҹ���ʯ������",
           "name" : "�Ϸ���Ƕ�����",
           "������" : "�Ϸ���Ƕ�����",
        ]) );

        setup();
        carry_object("/d/dali/npc/obj/pao")->wear();
}

void init()
{       
        object me,ob;
        ob = this_player();
	me = this_object();
        ::init();
        if( interactive(ob)
         && ob->query_temp("kill")){
         call_out("kill_ob", 0, ob); 
         }
}
