// hqniu.c ����ţ

#include <ansi.h>
inherit NPC;
void create()
{
        string weapon;
        set_name("����ţ",({"hu qingniu","hu","qingniu"}));
        set("title",HIY"����ҽ��"NOR);
        set("long", "�����Ǻųơ��������ȡ��ĵ���ҽ�ɺ���ţ��������㣬���ϴ�����Į֮�顣\n");
        set("age", 41);
        set("attitude", "friendly");
        set("shen", -1000);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("per", 30);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("eff_jingli", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("unique", 1);

        set_skill("sword",220);
        set_skill("dodge",220);
        set_skill("force", 220);
        set_skill("blade",220);
        set_skill("piaoyi-shenfa", 220);
        set_skill("shenghuo-lingfa", 220);
        set_skill("lieyan-dao", 220);
        set_skill("liehuo-jian", 220);
        set_skill("parry", 220);
        set_skill("cuff", 220);
        set_skill("qishang-quan",220);
        set_skill("literate", 200);
        set_skill("medicine", 200);

        set_skill("shenghuo-shengong",200);
        map_skill("force", "shenghuo-shengong");
        map_skill("cuff","qishang-quan");
        map_skill("blade","shenghuo-lingfa");
        map_skill("sword","liehuo-jian");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("parry", "shenghuo-lingfa");        
        prepare_skill("cuff","qishang-quan");        

        set("inquiry", ([
           "��˹����" : "����������Դ�ڲ�˹���̣����а�����ʷ��",
           "ʥ����" : "��˵ʥ�����������̵�ʥ�����ʼ�ղ���һ����ʵΪ���£�",
           "���ѹ�" : "���������ҵķ��ޣ��Һ�������......",
           "������" : "�����ˣ�������Ϊ���������ɷ�����������������",
//         "�ؼ�"  : (: ask_miji :),
        ]));
         
        setup();
        weapon = random(2)?"/clone/weapon/changjian":"/clone/weapon/tieling";
        carry_object(weapon)->wield();
        carry_object("/d/mingjiao/hdg/obj/qingpao")->wear();
}
