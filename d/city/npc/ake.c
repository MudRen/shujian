// ����

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "a ke", "ake" }));
        set("gender", "Ů��");
        set("unique", 1);
        set("age", 20);      
	      set("long","�������棬�ǽ�ӹС˵��¹���ǡ�������ľ�����Ů���������鲻�������ɫ��õ���¶���ܷ���������\n"
	      "������ǳ�ԣ���������֪���١����밢��һ��Ѱ��ʦ��ʱ������ΤС����ΤС��������������ɫ������\n"
	      "�����ô򣬵���һֱ������֣��ˬ����ΤС��̬���䵭���������Щ�˺�ΤС�����������������ܲң�\n"
	      "�����Գɺͳ�ԲԲ֮Ů��Сʱͬĸ�׾��������𸮣��󱻾���͵�ߣ�����Ϊ������Һޣ���������Ϊ��\n"
	      "��������֮Ů�����Խ�����ɱ������ʧ�ֺ��������Լ���������һ��ϣ����֣��ˬԶ�߸߷ɣ�������\n"
	      "����Ժ����ΤС���Ĺ��⣬�����ΤС��������\n");
	      set("str", 20);
        set("int", 20);
        set("con", 18);
        set("dex", 22);
        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "peaceful");
	      set("max_qi",100000);
        set("max_jing",100000);
        set("neili",0);
        set("max_neili",0);
	      set("jiali",0);

        set_skill("strike", 60);
	      set_skill("parry",80);
	      set_skill("sword",80);
        set_skill("dodge", 900);
	      set_skill("tiejian-jue",70);

	      map_skill("strike","luoyan-zhang");
	      map_skill("dodge","shenxing-baibian");       

        setup();
     
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt1")->wear();
        set("inquiry", ([ 
 ]));           
}
