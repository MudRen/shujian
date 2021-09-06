// xuan-ku.h for fight and get letter from Xuan

#include <ansi.h>

string* names = ({
	"chengguan luohan",
	"chengzhi luohan",
	"chengming luohan",
	"chengjing luohan",
	"chengjian luohan",
	"chengxing luohan",
	"chengji luohan",
	"chengmie luohan",
	"chenghe luohan",
});

void preparing(object, object);

string ask_me()
{
	mapping fam, my_fam, skl; 
        object fighter, me, room, monk;
	string *sname;
	int i,j;

	fighter = this_player();
	me = this_object();
	my_fam  = me->query("family");

	skl = fighter->query_skills();
        if (mapp(skl)) sname = keys(skl);

	if( fighter->query("luohan_winner") )
		return RANK_D->query_respect(fighter) + 
		"��Ȼ�����޺����󣬿ɲ�Ҫ�����Ŀ������Ц��";

	for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]] < 80 && sname[i] != "medicine") 
		return RANK_D->query_respect(fighter) + 
		"���������������ʸ��޺�����";
	}

	if ( mapp(fam = fighter->query("family")) 
	&& fam["family_name"] == "������"
	&& fam["generation"] != (my_fam["generation"] + 2))
		return RANK_D->query_respect(fighter) + 
		"���ݲ��ϣ������ʸ��޺�����";

        if ( (int)fighter->query("guilty") > 0 )
		return RANK_D->query_respect(fighter) + 
		"���۷����䣬�������������׼���㴳�޺�����";

	if ( me->query("assigned_fighter") )
		return RANK_D->query_respect(fighter) + 
		"��������������ս�޺��������һ��ʱ�������ɡ�";

	fighter->set_temp("xuanku-asked", 1);

	say("\n����˵�����ðɣ���ȥ�ټ��޺��ó��ϣ��Ժ����������䳡�ϵ��㡣\n");

	me->set("assigned_fighter", fighter->query("id")); 		
	
	if( !fighter->query_temp("xuannan-asked") )
	say("\n�����ֵ���������ȥ��֪���������Ѵ�ʦ�����������ټ����������޺���\n");

        message_vision("\n�����ʦ�����뿪��\n\n", fighter);

        for(j=1; j<10; j++) 
	{
                room = load_object("/d/shaolin/luohan" + j);
                
  		me->move(room);
                
		if( !objectp(monk = present(names[j-1], room) ))
		{
	        	me->move("/d/shaolin/lhtang");
                        me->delete("assigned_fighter");
        	        message_vision("\n�����ʦ���˹�����\n\n", fighter);
			return "���ǶԲ����޺��������˲��ڣ��޷������޺�����\n";	
		}

                message("vision", "\n�����ʦ���˹�������" + monk->query("name") + "��������˵�˼��䡣\n", room, monk);
                message("vision", monk->query("name") + "�޺����˵�ͷ�������ʦ�첽���˳�ȥ��\n", room, monk);
	}
	
        me->set("location", 1);	// ��ֹ reset �ٻ� Yuj 19991115
        me->move("/d/shaolin/hguangz2");

        call_out("waiting", 1, me, 0);

	return "�ã���Ҷ������ˡ�\n";
}

void waiting(object me, int wait_time)
{
	object fighter;

        if( wait_time >= 300 )
	{
		say( "����˵�����������������ˣ����ǻ�ȥ�գ�\n\n");
		call_out("do_back", 0, me);		
		return;
	}

	if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
	{
                call_out("waiting", 1, me, wait_time + 1);
		return;
	}
	if( !present("xuannan dashi", environment(me)) || !fighter->query_temp("xuannan-asked") )
	{
		if( random(10) == 0 ) 
		say("\n����˵����" + RANK_D->query_respect(fighter) + "ȥ�������Ѵ�ʦû�У� ���������ڸõ��˰գ�\n");

                call_out("waiting", 1, me, wait_time + 1);
		return;
	}
	preparing(me, fighter);
}

void preparing(object me, object fighter)
{
	object monk, room;

	room = load_object("/d/shaolin/hguangz2");

	monk = present("daojue chanshi", room);
	if (monk) {
		message("vision", "�����ʦ��������ʦ��������˵�˼��䡣\n", room, monk );
		monk->move("/d/shaolin/houdian");
		message("vision", monk->query("name") + "��ʦ���˵�ͷ���첽�����뿪��\n", room);
	}

	message("vision", HIY "\n�����ʦ�������������޺������Χ��\n" NOR, room);
	message("vision", "\nֻ����������ɳɳ�ĽŲ���������ʮ��λ�޺��Ǹ���������ɱ��\n"
		"����ֿ�ȭ�����ֱֳ�����������Χ����������ס��ͨ·��\n\n", room);

	say( "�����ֵ���׼�����޺����󼴿̷�����\n\n");

	fighter->delete_temp("xuannan-asked");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);

        call_out("fighting",  2, me, fighter, 0);
}

void fighting(object me, object fighter, int count)
{
	object monk1, room1, room2;

	if( count++ < 9 ) {
		room1 = load_object("/d/shaolin/luohan"+count);
		room2 = load_object("/d/shaolin/hguangz2");

		message("vision", "\n�޺������ٵ���ת�ţ�һ���������ս���\n" NOR, room2);

		monk1 = present(names[count-1], room1);
		if (monk1) {
			monk1->move(room2);
			monk1->move(room1);
		}
	}

	if (!fighter || !living(fighter) || environment(fighter)!=environment(me))
	{
		if( objectp(fighter)) {
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}

                command("chat* ҡ��ҡͷ��˵�����벻��... ����");
		command("sigh");
		call_out("do_back", 2, me );
		return;
	}
	if (count > 9)
	{
		if( objectp(fighter) && (int)fighter->query_temp("beat_count") >= 18 )	
                        call_out("do_recruit", 2, me, fighter);
		else
			call_out("do_back", 3, me );
	}
	else call_out("fighting", 2, me, fighter, count);
}

void do_recruit(object me, object fighter)
{
	mapping ft_fam;

	if (!objectp(fighter)) {
		call_out("do_back", 1, me);
		return;
	}
	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	fighter->add("combat_exp", 7500);
	fighter->set("luohan_winner", 1);

	command("chat* congra");
	if (!(ft_fam = fighter->query("family")) || ft_fam["family_name"] != "������")
	{
		command("bow");
		command("say " + RANK_D->query_respect(fighter) + "�˷����󣬵��Ա������д������棬�ٳ߸�ͷ������һ�������ľʹ˱����\n");
		call_out("do_back", 3, me );
	}
	else
	{
		command("say ��ϲ�㴳����ʮ���޺����󣡱����д˵Ƚܳ����ӣ���ʱ�ص�Ϊ���ַ�һ��ʣ�\n");
		call_out("do_back", 30, me );
	}
}

void do_back(object me)
{
        object monk, room1, room2;

	message("vision", "\n�����ʦ���˻��֣� �޺��ó������漴����뿪���䳡��\n", environment(me) );
	
        room1 = load_object("/d/shaolin/hguangz2");
        room2 = load_object("/d/shaolin/houdian");

        monk = present("daojue chanshi", room2);
        if (monk) monk->move(room1);

        me->delete("assigned_fighter");
	me->move("/d/shaolin/lhtang");
	me->delete("location");
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"]))
	{
		command("nod");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] <= (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "��ͽ����ô�ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query("luohan_winner") )
		{	
			command("say ���Ĵ���֮�꣬�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");

			name = ob->query("name");
			new_name = "��" + name[2..3];
			ob->set("name", new_name);
	
			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɳ��ֱ��޺�֮һ !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "����û�д���ʮ���޺����󣬲���Խ����ʦ��");
		}
	}
}
