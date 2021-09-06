#include <ansi.h>
inherit NPC;
string *first_name = ({
"��", "��", "��", "��", "��", "��", "��", "��","��","��","��","��","��",
});
string *first_name_id = ({
"ru", "ruo", "hui", "su", "xian", "jia", "wen", "shu", "rui", "miao", "rou", "cui", "xiao",
});

string *name_words = ({
"÷", "��", "��" ,"��", "��", "��", "��", "��","ѩ","õ","��","��","Ƽ",
});

string *name_words_id = ({
"mei", "lan", "zhu", "ju", "yun", "yu", "wu", "wen", "xue", 
"mei", "yu", "min", "ping", 
});
                               
void create()
{
	int i,j,k;
	string name,name_word;
	i = random(sizeof(first_name));
	name = first_name[i];
       
	j = random(sizeof(name_words));
	name += name_words[j]; 
	name_word = name_words_id[j];

	if( random(10) > 5 ){
		k = random(sizeof(name_words));
		name += name_words[k];
		name_word = name_word + name_words_id[k];
	}

	set_name(name, ({ first_name_id[i]+" "+name_word, first_name_id[i], name_word}) );
	set("title", HIY"���չ���Ů"NOR);
	set("long", "����һ��"+this_object()->query("title")+"������"+this_object()->query("name")+"��\n");
	set("gender", "Ů��" );
	set("age", 15+random(10));
	set("per",25+random(5));
	set("attitude", "peaceful");

	set("str",15+random(13));
	set("int",20);
	set("con",15+random(12));
	set("dex",15+random(10));
	set("max_qi", 300+random(200));
	set("max_jing", 200)+random(200);
	set("neili", 250+random(200));
	set("max_neili", 250+random(200));
	set("combat_exp", random(6000)+20000);

	create_family("���չ�",4,"����");
        set_skill("force", 25+random(15));
        set_skill("bahuang-gong", 30);
        set_skill("dodge", 25+random(15));
        set_skill("yueying-wubu", 30);
        set_skill("strike", 25+random(15));
        set_skill("liuyang-zhang", 30);
        set_skill("parry", 25+random(15));
	set_skill("literate", 60);

        map_skill("force", "bahuang-gong");
        map_skill("dodge", "yueying-wubu");
        map_skill("parry", "liuyang-zhang");
        map_skill("strike", "liuyang-zhang");
        prepare_skill("strike", "liuyang-zhang");

	set("shen_type", 0);
	set("inquiry", ([
		"name": "ū�ҽ���"+this_object()->name()+"����ʮ�������Ͷ������ѧ�ա�",
		"rumors": "������ټ���������",
		"here": "���������չ�����û�»��ǲ�Ҫ�����ת�ĺá�",
		"���չ�": "����������չ�������",
	]));
	setup();
	carry_object(__DIR__"obj/f-cloth")->wear();
}  

#include "npc.h"
