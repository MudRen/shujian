// zhou.c ������
// modified by zly 6/6/99

#include <ansi.h>
#include <wanted.h>
inherit NPC;

#include "/d/zhiye/npc/biaotou.h"

void create()
{
        set_name("�ܻ���", ({"zhou huwei", "huwei", "zhou"}));
        set("title", YEL"�����ھ�"NOR);
        set("nickname", "������˷�");
        set("shen_type", -1);
        set("gender", "����");
        set("age", 58);
        set("long", 
                "�����ͷ����������֪�������ǻ����ھֵ�����ͷ����������һ�㶼�����ۡ�\n"
                "�����ְ����������ޣ�����ؿ������ܡ�\n"
        );

        set("attitude", "peaceful");
        
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 2000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 60);
        
        set("combat_exp", 1500000);
        
        set_skill("force", 200); 
        set_skill("strike", 200);
        set_skill("lianhua-zhang", 200);
        set_skill("huntian-qigong", 200);       
	set_skill("dodge", 200);                        
        set_skill("xiaoyaoyou", 200);           
        set_skill("parry", 200);                        
        set_skill("whip", 200);         
        set_skill("huifeng-bian", 200);
                
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "huifeng-bian");
        map_skill("whip","huifeng-bian");
        map_skill("strike", "lianhua-zhang");
        prepare_skill("strike", "lianhua-zhang");
        set("chat_chance", 3);
        set("chat_msg", ({
		"����������˵�������������Ե����̵�һʱ֮�����������֮�֡��� \n",
		"�����ŵ�����: �����������Ե������鲻���֣����ֲ����顱��\n",
		"������С�����������������Ե���ֻҪ���ֶ࣬��¥̧���ӡ���\n",
	}));   
	
	set("inquiry", ([
		"����"		: (: ask_guard :),
		"guard"		: (: ask_guard :),
		"����1"		: (: ask_guard1 :),
		"guard1"	: (: ask_guard1 :),
		"����2"		: (: ask_guard2 :),
		"guard2"	: (: ask_guard2 :),
		"����3"		: (: ask_guard3 :),
		"guard3"	: (: ask_guard3 :),
	]));
	
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(BINGQI_D("tiewhip"))->wield();
} 
