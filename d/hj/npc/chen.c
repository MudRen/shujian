// dingtong.c
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("�´ﺣ", ({ "chen dahai", "chen", "dahai" }) );
       set("title", "��ʦ");
       set("nickname", "������");
       set("gender", "����" );
       set("shen", -2500);
       set("age", 43);
       set("unique", 1);
       set("str", 23);
       set("con", 20);
       set("int", 20);
       set("dex", 22);
       set("env/wimpy", 60);
       set("long","
һ������Ƥ���ĸߴ��ӣ����������˵�Ĺ�������ܲ�������
��Ŀ�⾼�����������һ�����������ǻ�Ԫ�����µ���ʦ֮һ��\n" );
       set("combat_exp", 250000);
       set("attitude", "heroism");
       set("chat_chance", 3);
       set("chat_msg", ({ (: random_move :) }) );          
       set("max_qi", 600);
       set("max_jing", 500);
       set("neili", 700);
       set("max_neili", 700);
       set("jiali", 10);
       
       set_skill("force", 60); 
       set_skill("unarmed", 30);
       set_skill("sword", 60);
       set_skill("dodge", 60);
       set_skill("parry", 60);
       set_skill("qingmang-jianfa", 60); 
       map_skill("sword", "qingmang-jianfa");
       map_skill("parry", "qingmang-jianfa");
       
       setup();
       carry_object(BINGQI_D("jinjian"))->wield();
       carry_object(ARMOR_D("cloth"))->wear();
       add_money("silver", 10);
}

#include "bs.h";
