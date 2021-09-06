// dingtong.c
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("��ͬ", ({ "ding tong", "ding", "tong" }) );
       set("title", "��ʦ");
       set("nickname", "��ͷ��");
       set("gender", "����" );
       set("shen", -2000);
       set("age", 45);
       set("str", 20);
       set("con", 20);
       set("int", 20);
       set("dex", 20);
       set("env/wimpy", 60);
       set("long","���ǻ�Ԫ�����µ���ʦ֮һ��һֱ����һ��Ѱ����һ���ˡ�\n" );
       set("unique", 1);
       set("combat_exp", 200000);
       set("attitude", "heroism");
       
       set("chat_chance", 3);
       set("chat_msg", ({(: random_move :) }) );          
       set("max_qi", 500);
       set("max_jing", 500);
       set("neili", 600);
       set("max_neili", 600);
       set("jiali", 10);
       
       set_skill("force", 60); 
       set_skill("unarmed", 30);
       set_skill("qingmang-jianfa", 50);
       set_skill("sword", 60);
       set_skill("dodge", 60);
       set_skill("parry", 60);
       map_skill("sword", "qingmang-jianfa");
       map_skill("parry", "qingmang-jianfa");
       
       setup();
       carry_object(BINGQI_D("yinjian"))->wield();
       carry_object(ARMOR_D("cloth"))->wear();
       add_money("silver", 1);
}

#include "bs.h";
