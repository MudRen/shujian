// Jiaozhong.c ����
// By Numa@Sj 2000.2.15

#include <ansi.h>
inherit NPC;

string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��", "��","��" }); 
string *name_words = ({ "˳","��","��","��","��","��","��","��","־","��", "Т","��","��","��","��",
"��","��","ʢ","ʤ","��","��","��","ͬ","��", "��","��","��","¡","��","��","��","��","��" });
string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne"}); 
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

void create()
{
	string name, id;
	
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
        if( random(10) > 4 ) 
                name += name_words[random(sizeof(name_words))];
        id = rnd_id[random(sizeof(rnd_id))]; 
        if( random(10) > 4 ) 
                id += rnd_id[random(sizeof(rnd_id))]; 
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];
        set_name(name, ({"jiao zhong","zhong",id}));
        set("title","������̽���");
        set("age", 16 + random(10));
        if (random(2)>0)
        	set("gender","����");
        else set("gender","Ů��");
        set("attitude", "friendly");
	set("shen", 8000);
        set("combat_exp", 50000 + random(5000));
        set_skill("sword",  50);
        set_skill("dodge",  50);
        set_skill("force",  50);
        set_skill("parry",  50);

/*
        set_skill("tianmo-jian", 50);
        set_skill("tianmogong", 50);
        set_skill("ding-dodge",50);

	map_skill("force", "tianmogong");
	map_skill("parry", "tianmo-jian");
	map_skill("sword", "tianmo-jian");
       	map_skill("dodge", "ding-dodge");
*/
	create_family("�������", 6, "����");
 
        setup(); 
	if (random(2)>0)
	carry_object(BINGQI_D("changjian"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
}
