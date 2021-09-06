// hui.h for fight and get letter from Hui

int accept_object(object ob, object obj)
{
	object me = this_object();
	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if (ob->query_temp("have_letter") && present("tuijian xin3", ob))
	{
		command("say ��ô���������ҵ��Ƽ���ȥ��ʦ����");
		return 0;
	}

	if (obj->id("damo ling")
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") )
	{
		ob->set_temp("fight_ok3",1);
	        command("say �ã���Ȼ�ѵõ����ɵ���ɣ����Ǿ�����֤һ���书��");
		call_out("destroying", 1, obj);
		return 1;
	}

	if (obj->id("tuijian xin2")
	&& ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
		command("say �ã�" + ob->query("name") + "����Ը�����Ϊʦ��");
		remove_call_out("destroying");
		call_out("destroying", 1, obj);
		return 1;
	}

	command("smile");
	command("say �ⶫ�����ҿ�û��ʲô�á�");
	return 0;
}

void destroying(object obj)
{
	if (obj)
		destruct(obj);
}

int accept_fight(object ob)
{
	object me  = this_object();

	if ( !ob->query_temp("fight_ok3") ) return 0;

	if(me->query("eff_qi") < me->query("max_qi") ||
	me->query("qi") < me->query("eff_qi") ||
	me->query("neili") < me->query("max_neili")) {
		command("say ��ѽ������������о���̫�ã����һ��������ɡ�");
		return 0;
	}
	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	ob->delete_temp("fight_ok3");

	return 1;
}

void checking(object me, object ob)
{

	object obj;
	int my_max_qi, his_max_qi;

	if (!ob) return;
	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting())
	{
		call_out("checking",1, me, ob);
		return;
	}

	if ( !present(ob, environment()) ) return;

	if (query_temp("last_lost_to") == ob) {
		if (me->query_temp("last_damage_from") == ob) {
			command("say ���������ʤ������" + RANK_D->query_respect(ob) +"�����������µļѵ��ӣ���ϲ���ˣ�");
			message_vision("$N����$nһ���Ƽ��š�\n", me, ob);
			ob->set_temp("have_letter",1);
			obj=new("/d/shaolin/obj/tuijianxin-3");
			obj->move(ob);
			return;
		}
		command("say ���ֳ�����������ϲ�����׵ĵ��ӣ������߳ܰ���");
		return;
	}

	command("say ����" + RANK_D->query_respect(ob) +
		"���ö����ϰ�������������������г���ͷ�� !\n");

	return;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

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

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��")
	{
		command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");

			command("say ��" + ob_fam["master_name"] + "���������ҵİɣ������� !");
			command("say ƶɮ�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");

			new_name = "��" + name[2..3];
			ob->set("name", new_name);

			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɵ��ֱ����� !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "����û���Ƽ��ţ�����Խ����ʦ��");
			return;
		}
	}

	return;
}
