// movedata.c
// By River@SJ 2002.4.5
// YUJ@SJ 2002-04-08

inherit F_CLEAN_UP;

#define NID_PATH "/u/river/data/"
#define ID_PATH "/data/"
#define ODB "/clone/user/olduser"

int check_legal_id(string id)
{
	int i;

	i = strlen(id);
	if( i < 3 || i > 8 ) {
		write("�Բ�����ID������ 3 �� 8 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
	if( id[i] < 'a' || id[i] > 'z' ) {
		write("�Բ�����IDֻ����СдӢ����ĸ��\n");
		return 0;
	}
	return 1;
}

int check_legal_email(string email)
{
	if (sscanf(email, "%*s@%*s.%*s") == 3) return 1;
	write("email ��ʽ���ԡ�\n");
	return 0;
}

mapping olddb, newdb;

varargs void dup(string key)
{
	newdb[key] = olddb[key];
}

int main(object me, string arg)
{
	string id, nid, email, status, msg, oldemail, passwd;
//	mapping job;
	int i, j, q, days;

	seteuid(ROOT_UID);

	if (!arg) return notify_fail("ָ���ʽ��movety <ID> [new ID] <email>  <days>\n");

	if (sscanf(arg, "%*s %*s %*s %*s %*s") == 5)
		return notify_fail("ָ���ʽ��movety <ID> [new ID] <email> <days>\n");
	if (sscanf(arg, "%s %s %s %d", id, nid, email, days) == 4)
		q = 0;
	else if (sscanf(arg, "%s %s %d", id, email, days) == 3) {
		nid = id;
		q = 1;
	} else return notify_fail("ָ���ʽ��movety <ID> [new ID] <email> <days>\n");

	if (!check_legal_id(nid))
		return notify_fail("ָ���ʽ��movety <ID> [new ID] <email> <days>\n");

	if (!check_legal_email(email))
		return notify_fail("ָ���ʽ��movety <ID> [new ID] <email> <days>\n");

	if (days < 30) {
		write("��Ч��������ȷ��\n");
		return notify_fail("ָ���ʽ��movety <ID> [new ID] <email> <days>\n");
	}

	if (!ODB->restore(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION))
		return notify_fail(capitalize(id) +" ��¼���������ڡ�\n");

	if (!ODB->restore(NID_PATH +"user/"+ id[0..0] +"/"+ id + SAVE_EXTENSION))
		return notify_fail(capitalize(id) +" ���ݵ��������ڡ�\n");

	if (file_size(ID_PATH +"login/"+ nid[0..0] +"/"+nid + SAVE_EXTENSION) != -1)
		return notify_fail(capitalize(nid) + " ����û��Ѿ������ˡ�\n");

	olddb = ODB->query_dbase();
	newdb = ([ ]);

	// hp ����, max_jing max_qi eff_jingli ��ϵͳ�Զ�����
	dup("jing");
	dup("eff_jing");

	dup("jingli");
	dup("max_jingli");

	dup("qi");
	dup("eff_qi");

	dup("neili");
	dup("max_neili");
/*
	if ( olddb["max_neili"] > 8500 )
		newdb["max_neili"] = 8500;
*/
	dup("shen");

	dup("food");
	dup("potential");
	dup("water");
	dup("combat_exp");

	// score ����
	if ( olddb["class"] && olddb["class"] != "eunuch")
		dup("class");
	dup("title");
	dup("str");
	dup("con");
	dup("name");
	newdb["id"] = nid;
//	dup("id");
	dup("dex");
	dup("int");

	dup("nickname");
	dup("mud_age");
	dup("birthday");

	dup("gender");
	if (newdb["gender"] != "Ů��")
		newdb["gender"] = "����";

	newdb["mud_time"] = olddb["mud_age"];
	newdb["startroom"] = "/d/city/kedian/bonus_room";

	dup("PKS");
	dup("MKS");
	dup("BKS");
	dup("GKS");
	dup("death_count");
	dup("death_times");
	dup("balance");
	if (olddb["balance"] > 10000000)
		newdb["balance"] = 10000000;

	if (mapp(olddb["family"]))
		newdb["family"] = copy(olddb["family"]);

	dup("per");
	dup("kar");
	dup("pur");

	newdb["oldsj"] = 1;
	newdb["name"] = "���ִ���";

	if ( olddb["luohan_winner"] )
		newdb["luohan_winner"] = 1;

	if ( olddb["muren_winner"] )
		newdb["muren_winner"] = 1;

	if ( olddb["tls"] )
		newdb["tls"] = 1;

	if ( olddb["xie_qishang"] )
		newdb["xie_qishang"] = 1;
	
	if ( olddb["gb_bags"] )
		newdb["gb_bags"] = 1;

// Job time
	newdb["job_time"] = ([ ]);

	if (olddb["dali_job"])
		newdb["job_time"]["����"] = olddb["dali_job"];
	if (olddb["gb_job"])
		newdb["job_time"]["ؤ��"] = olddb["gb_job"];
	if (olddb["gb_job2"])
		newdb["job_time"]["��Ч����"] = olddb["gb_job2"];
	if (olddb["gf_job"])
		newdb["job_time"]["�ٸ�"] = olddb["gf_job"];
	if (olddb["hs_job"])
		newdb["job_time"]["��ɽ"] = olddb["hs_job"];
	if (olddb["mingjiao_job"])
		newdb["job_time"]["����"] = olddb["mingjiao_job"];
	if (olddb["mr_job"])
		newdb["job_time"]["Ľ��"] = olddb["mr_job"];
	if (olddb["sl_job"])
		newdb["job_time"]["����"] = olddb["sl_job"];
	if (olddb["snake_job"])
		newdb["job_time"]["ץ��"] = olddb["snake_job"];
	if (olddb["songshan_points"])
		newdb["job_time"]["��ɽ"] = olddb["songshan_points"];
	if (olddb["thd_job"])
		newdb["job_time"]["�һ���"] = olddb["thd_job"];
	if (olddb["wd_job"])
		newdb["job_time"]["�䵱"] = olddb["wd_job"];
	if (olddb["xs_job"])
		newdb["job_time"]["ѩɽ"] = olddb["xs_job"];
	if (olddb["xx_job4"])
		newdb["job_time"]["���ް���"] = olddb["xx_job4"];
	if (olddb["xx_job5"])
		newdb["job_time"]["������ͽ"] = olddb["xx_job5"];
	if (olddb["xx_points"])
		newdb["job_time"]["����"] = olddb["xx_points"];
	if (olddb["zhao_job"])
		newdb["job_time"]["����"] = olddb["zhao_job"];

// �������������������ת��
/*
	if ((exp = newdb["combat_exp"]) > 3000000) {
		float scale = 3000000.0 / exp;

		newdb["combat_exp"] = 3000000;
		newdb["mud_age"] = to_int(newdb["mud_age"] * scale);
		newdb["PKS"] = to_int(newdb["PKS"] * scale);
		newdb["BKS"] = to_int(newdb["BKS"] * scale);
		newdb["GKS"] = to_int(newdb["GKS"] * scale);
		newdb["MKS"] = to_int(newdb["MKS"] * scale);
		newdb["death_count"] = to_int(newdb["death_count"] * scale);
		newdb["death_times"] = to_int(newdb["death_times"] * scale);
		if (job = newdb["job_time"]) {
			string *jobs = keys(job);
			i = sizeof(jobs);
			for (j = 0; j < i; j ++)
				job[jobs[j]] = to_int(job[jobs[j]] * scale);
		}
	}

	if ( newdb["mud_age"] > 7840000 )
		newdb["mud_age"] = 7840000;
*/
	ODB->set_dbase(newdb);

	status = read_file(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION);

	sscanf(status, "%*s\"email\":\"%s\",", oldemail);
	status = replace_string(status, "\"email\":\""+oldemail+"\",", "\"email\":\""+email+"\",");

	sscanf(status, "%*s\"password\":\"%s\",", passwd);
	if (q)
		msg = "��� "+ capitalize(id) +" �Ѿ�������ϡ�\n";
	else {
		status = replace_string(status, "\"id\":\""+id+"\",", "\"id\":\""+nid+"\",");
		msg = "��� "+ capitalize(id) +" ������ϣ����� ID Ϊ "+ capitalize(nid) +" ��\n";
	}

	if ( ! write_file(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION, status, 1))
		return notify_fail("�ļ� "+ NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION +" �洢ʧ�ܡ�\n");

	if (!cp(NID_PATH +"login/" + id[0..0] +"/"+ id + SAVE_EXTENSION, ID_PATH +"login/"+ nid[0..0] +"/"+nid + SAVE_EXTENSION)
	|| !ODB->save(ID_PATH +"user/" + nid[0..0] +"/"+nid + SAVE_EXTENSION))
		return notify_fail("�洢�ļ�ʧ�ܡ�\n");		// д����ʧ��

	write(msg);
	i = db_connect("localhost","mud","root");
	if (!intp(i)) return notify_fail("�������ݿ�ʧ�ܣ�"+i+"��\n");
	j = db_exec(i,"replace into Users set "
		"U_Username='"+nid+"',"
		"U_Name='"+newdb["name"]+"',"
		"U_Password='"+passwd+"',"
		"U_Email='"+email+"',"
		"U_Site='TY',"
		"Mud_Site='TY',"
		"U_Online='N',"
		"Alivedays="+save_variable(days)
	);
	db_close(i);
	if (!intp(j)) return notify_fail("���ݿ����ʧ�ܣ�"+j+"\n");
	write(sprintf("%s -> %s, %s, %d\n", id, nid, email, days));
// log file
	log_file("static/MOVEDATA",
		sprintf("%8s%-10s �� %-8s ����Ϊ %-8s, %s, %d TY\n",
			me->query("name"), "("+ geteuid(me)+")", id, nid, email, days), me);
	return 1;
}

int help()
{
	write(@HELP

ָ���ʽ��movety <ID> [New ID] <email> <days>

��ָ����������������ݣ���� New ID ��ȱ���Ͳ��� ID��

HELP
	);
	return 1;
}
