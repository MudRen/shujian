// Npc: /d/tianshan/npc/f-dizi.c
// By Linux

#include <ansi.h>

inherit NPC;

string *first_name = ({ "��","��","л","��","��","��","֣","��","��","��","��","��" }); 
string *first_name_id = ({
"zhao","he","xie","li","su","wu","zheng","wen","zhang","chen","liu","lin"});
string *name_words = ({
"��","��","��","��","��","��","��","��","��","��","��","��","�","��",
"��","��","��","��","��","��","��","ٻ","Ƽ","��","ϼ","��","��","��",
"Ӣ","��","��","��","��",
});
string *name_words_id = ({ 
"chun","dan","fang","fen","feng","gu","hong","hong","jiao","juan","ju","lan","lan","li",
"li","lian","ling","lin","na","qin","qin","qian","ping","ting","xia","xiang","yan","yan",
"ying","ying","yu","zhen","zhu", });

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
	set("gender", "Ů��" );
	set("age", 15+random(10));
	set("per",25+random(5));
	set("attitude", "peaceful");
	set("str",15+random(13));
	set("int",20);
	set("con",15+random(12));
	set("dex",15+random(10));
	set("max_qi", 400+random(200));
	set("eff_jingli", 400);
	set("max_jing", 200)+random(200);
	set("max_neili", 750+random(200));
	set("combat_exp", random(16000)+25000);

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

void init()
{
	object me=this_object();
	string room;
	room=environment(me)->query("short");
	switch (room) {
		case "��첿":
			me->set("title",WHT"���չ���첿����"NOR);
		break;
		case "���첿":
			me->set("title",HIC"���չ����첿����"NOR);
		break;
		case HIR"���첿"NOR:
			me->set("title",HIR"���չ����첿����"NOR);
		break;
		case "���첿":
			me->set("title",HIR"���չ����첿����"NOR);
		break;
		case "���첿":
			me->set("title",HIG"���չ����첿����"NOR);
		break;
		case "���첿":
			me->set("title",HIY"���չ����첿����"NOR);
		break;
		case "��첿":
			me->set("title",HIB"���չ���첿����"NOR);
		break;
		case "���첿":
			me->set("title",HIW"���չ����첿����"NOR);
		break;
		case "���첿":
			me->set("title",MAG"���չ����첿����"NOR);
		break;
		default:
    			me->set("title",WHT"���չ�����"NOR);
    		break;
	}
	set("long", "����һ��"+this_object()->query("title")+"������"+this_object()->query("name")+"��\n");
}

#include "npc.h";
