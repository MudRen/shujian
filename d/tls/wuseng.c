inherit NPC;


void create()
{
	set_name("��������ɮ", ({
		"wu seng",
		"seng",
			}));
	set("long",
		"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ��\n"
		"��һϮ��ɫ���£��ƺ���һ�����ա�\n"
	);

	set("gender", "����");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("shen",1000);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("pursuer", 1);
	set("combat_exp",40000);
	set("score", 1000);
        
	set_skill("force", 60);
	set_skill("qiantian-yiyang", 60);
	set_skill("dodge", 60);
	set_skill("tianlong-xiang", 60);
	set_skill("unarmed", 60);
	set_skill("yiyang-zhi", 60);
	set_skill("parry", 60);
	set_skill("finger", 60);
	
	map_skill("force", "qiantian-yiyang");
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "yiyang-zhi");
	map_skill("finger", "yiyang-zhi");
       prepare_skill("finger","yiyang-zhi");		


	setup();

}



