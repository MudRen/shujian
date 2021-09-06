// cheng.h for fight and get letter from Cheng

void init()
{
	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting") && living(this_player()))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"), 1);
		this_player()->add_temp("beat_count", 1);
	}
}

int accept_object(object ob, object obj)
{
	if (obj->id("tuijian xin3")
	&& ob->query_temp("have_letter"))
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
		command("say " + ob_fam["master_name"] + "��ͽ����ô�ܵ���������ˣ���������");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");

			command("say ��" + ob_fam["master_name"] + "���������ҵİɣ���������");
			command("say ƶɮ�ֵ�һ����֮�ţ����ǿ�ϲ�ɺأ�");

			new_name = "��" + name[2..3];
			ob->set("name", new_name);

			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɻ��ֱ����ӣ�");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "����û���Ƽ��ţ�����Խ����ʦ��");
		}
	}
}
