inherit F_CLEAN_UP;

#define NID_PATH "/log/data/"
#define ID_PATH "/data/"

private int check_passwd(string id, string passwd)
{
	string pass;

	sscanf(read_file(NID_PATH+"login/"+id[0..0]+"/"+id + SAVE_EXTENSION), "%*s\"password\":\"%s\",", pass);
	return (crypt(passwd, pass) == pass);
}

private string change_id(string stat, string id, string nid)
{
	return replace_string(stat, "\"id\":\""+id+"\",", "\"id\":\""+nid+"\",");
}

private int copy_file(string id, string nid)
{
	if (write_file(ID_PATH+"login/"+nid[0..0]+"/"+nid+SAVE_EXTENSION,
	change_id(read_file(NID_PATH+"login/"+id[0..0]+"/"+id + SAVE_EXTENSION), id, nid),
	1) &&
	write_file(ID_PATH+"user/"+nid[0..0]+"/"+nid+SAVE_EXTENSION,
	change_id(read_file(NID_PATH+"user/"+id[0..0]+"/"+id + SAVE_EXTENSION), id, nid),
	1))
		return 1;
	return 0;
}

private int del_file(string id)
{
	if (rm(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION)
	&& rm(NID_PATH +"user/" + id[0..0] +"/"+ id + SAVE_EXTENSION))
		return 1;
	return 0;
}

private int check_legal_id(string id)
{
	int i;
	i = strlen(id);
	if( i < 3 || i > 8 ) {
		write("�� ID ������ 3 �� 8 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
		if( id[i] < 'a' || id[i] > 'z' ) {
			write("�� ID ֻ����СдӢ����ĸ��\n");
			return 0;
		}
	return 1;
}

void do_change(string id, string nid, string passwd)
{
	if (wiz_level(id) || wiz_level(nid))
	{
		write("�����������������\n");
		return;
	}
	if (file_size(NID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0) {
		write(capitalize(id) +" ��¼���������ڣ��޷����� ID��\n");
		return;
	}
	if (file_size(NID_PATH +"user/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0) {
		write(capitalize(id) +" ���ݵ��������ڣ��޷����� ID��\n");
		return;
	}
	if (!check_passwd(id, passwd))
	{
		write("���벻�ԡ�\n");
		return;
	}
	// ���û�д���ң���׼�� id
	if (file_size(ID_PATH +"login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0 ||
	file_size(ID_PATH +"user/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0)
	{
		if (id != nid) write(capitalize(id) + " ����ռ�ã����Ը��� ID �����󣬼���ʹ��ԭ ID��\n");
		nid = id;
	}
	else if (file_size(ID_PATH +"login/"+ nid[0..0] +"/"+ nid + SAVE_EXTENSION) >0
	&& file_size(ID_PATH +"user/"+ nid[0..0] +"/"+ nid + SAVE_EXTENSION) > 0)
	{
		write(capitalize(nid) +" �Ѿ����ڣ���ѡ���� ID ����ת����\n");
		return;
	}
	if (!check_legal_id(nid)) return;

	write("����ת�� "+id+" -> "+nid+" ... ");
	if (!copy_file(id, nid))
	{
		write(" ʧ��\n");
		log_file("CHANGE", sprintf("%s %s -> %s ����ʧ��\n", ctime(time())[4..19], id, nid));
		return;
	}
	write(" �ɹ�\nɾ��ԭʼ���� ... ");
	if (!del_file(id))
	{
		write(" ʧ��\n");
		log_file("CHANGE", sprintf("%s %s -> %s ɾ��ʧ��\n", ctime(time())[4..19], id, nid));
		return;
	}
	write(" �ɹ�\nת�����\n");
	log_file("CHANGE", sprintf("%s %s -> %s �ɹ�\n", ctime(time())[4..19], id, nid));
}

private void create()
{
	seteuid(getuid());
}
