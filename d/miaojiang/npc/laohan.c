// �Ϻ�

inherit NPC;
int ask_me(); 
 
 
void create()
{
	set_name("�����Ϻ�", ({ "miaozu laohan","laohan" }) );
	set("gender", "����" );
	set("age", 64);
	set("long",
		"����һλ�������Ƶ�������ߡ�\n");
	set("combat_exp", 30000);
	set("attitude", "peaceful");
	 
        set("inquiry", ([
		"name" : "���պΣ������ʱ������ԭ�������Ϊ���������������ˡ�\n",
                "here" : "��������置����Զ�����嶾�̵Ľ��أ�Ҫȥ����С��Щ�ɡ�\n",
		"����": (: ask_me :),
	]) );
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

int ask_me()
{
        object chan, me, ob;

        me = this_object();
        ob = this_player();
        
        if ( present("xiao tiechan", ob) )
	{
		command("say �㲻�������𣬻���Ҫʲ�᣿\n");
		return 1;
	}
	chan = new(__DIR__"obj/tiechan");
        command("look " + ob->query("id")); 
        command("say ����������һ������ûʲ���ã���Ҫ����ȥ�ɡ�\n");
	chan->move(ob);
	message_vision("$N����$nһ��������\n", me, ob);
	return 1;
}

