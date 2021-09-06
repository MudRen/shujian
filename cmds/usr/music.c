// by lane@����

#include <ansi.h>
inherit F_CLEAN_UP;

int sort_skill(string file)
{
	int i;
	if ( file[<2..<1] != ".c" ) return 0;
	if ( !sscanf(file, "%*s.c") )  return 0;
	if ( sscanf(file, "%*s_noshow.c") )  return 0;
	i = strlen(file);
	while(i--){
		if( file[i] == '.' ) continue;
		if( file[i] < 'a' || file[i] > 'z' )
			return 0;
	}

	return 1;
}

int sort_skill2(string sk) 
{
	return (SKILL_D(sk)->type() == "knowledge" && SKILL_D(sk)->type2() == "music");
}

int check_music(object me)
{
	int i, j, k;
	mapping music;

	music = me->query("music");
	if( !mapp(music) ) music = ([]);
	if( !arrayp(keys(music)) ) return 1;
	k = sizeof(keys(music));

	if( k > 0 ) {
		for( i=0; i < k; i++ ) {
			if( file_size("/d/music/book/"+keys(music)[i]+".c") < 0 ) {
				tell_object(me, HIY"�㷢���Լ�������һ�׾�������ס�\n"NOR);
				me->delete("music/"+keys(music)[i]);
				return 0;
			}

			if( wizardp(me) ) tell_object(me, HIY"���("+keys(music)[i]+")������Ϊ��"+me->query("music/"+keys(music)[i] )+"��ѧϰʱ��Ϊ��"+me->query("music_time/"+keys(music)[i] )+"������ʱ��Ϊ��"+time()+"��\n"NOR);

			if( !me->query("music_time/"+keys(music)[i] ) )
				me->set("music_time/"+keys(music)[i], time() );

// ���� yeju@SJ Ҫ��ÿ��������� 5 �� buy lane@none

			if( ( j = ( time() - me->query("music_time/"+keys(music)[i]) ) / 86400 ) >= 1 ) {
				me->add("music_time/"+keys(music)[i], j*86400 );
				if( wizardp(me) ) tell_object(me, HIY"���("+keys(music)[i]+")�������½���"+j*5+"�㡣\n"NOR);
				me->add("music/"+keys(music)[i], -j*5 );
				if( me->query("music/"+keys(music)[i]) < 1 )
					me->set("music/"+keys(music)[i], 0);
			}
		}
	} else return 0;

	return 0;
}

int main(object me,string arg)
{
	object ob;
	mapping book;
	mapping skl, lrn, map;
        
	string *sname, *mapped, *allskills, str = "", str2 = "", bname;
	int i, j, k, n;
	seteuid(getuid());

	if( !arg ) ob = me;
	else {
		ob = present(arg, environment(me));
		if( !ob ) ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = LOGIN_D->find_body(arg);
		if( !ob || !me->visible(ob) ) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
		if( wiz_level(me) < wiz_level(ob) ) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	}

	skl = ob->query_skills();
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});
	
	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	allskills  = sort_array( keys(skl), (: strcmp :) );	
	
	sname  = filter_array( allskills, (: sort_skill2 :) );
	allskills -= sname;
	j = sizeof(sname);

	if( j > 0 ) {
		str = HIW"��";
		str += (ob==me?"��":ob->name(1))+"�������ܱ�"NOR"��\n";	
		str += "��������������������������������������������������������������������������������������������\n";
		str += sprintf("%-90s", "���ܹ�"+chinese_number(j)+"���");
		for(i=0; i < j; i++) {
			if( i % 2 == 0 ) str += "��\n��";
			else str += "  ";
			str += sprintf("%s%-8s%-14s"HIC"��"NOR"%s %3d/%6d",
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
				to_chinese(sname[i]), "(" + sname[i] + ")",
				"/cmds/skill/skills.c"->skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
				skl[sname[i]], (int)lrn[sname[i]],);
			if( i > j-2 && i % 2 == 0 )
				str +="                                             ";
		}
		str += "��\n��������������������������������������������������������������������������������������������\n";
	}
	else
		str += HIW+" "+(ob==me ? "��" : ob->name(1)) + "Ŀǰ��û��ѧ���κ������ܡ�\n"NOR;
	write (str);		       

// ���ױ��Ϊ (music/***)
	check_music(ob);

	book = ob->query("music");
	if( !mapp(book) ) book = ([]);
	if( !arrayp(keys(book)) ) return 1;
	k = sizeof(keys(book));

	if( k <= 0 ) str2 = HIW+" "+(ob==me ? "��" : ob->name(1))+"Ŀǰ�в��ᵯ���κ����ס�\n"+NOR;

	else {
		str2 = HIW+"��"+(ob==me ? "��" : ob->name(1))+"Ŀǰ��������������С�"+NOR;
		str2 += "\n��������������������������������������������������������\n";

		for( i=0; i < k; i++ ) {
			if( file_size("/d/music/book/"+keys(book)[i]+".c") < 0 ) {
				if( wizardp(ob) ) tell_object(ob, HIY"�㷢���Լ�������һ�׾��������("+keys(book)[i]+")��\n"NOR);
				ob->delete("music/"+keys(book)[i]);
				return 0;
			}
			bname = call_other("/d/music/book/" + keys(book)[i], "book_name");
			if( !bname ) bname = "������";
			bname = "��"+bname+"��("+YEL+keys(book)[i]+NOR+")";
			str2 += sprintf(" %-58s", bname);

// ������ 10��Ϊ1���ȼ���10���ȼ��ⶥ
// ��������� = 0 ��ʹ��ʱ����ʾ ����
			n = ( ob->query("music/"+keys(book)[i]) + 9 ) / 10;
			if( n  < 1 ) str2 += HBRED"����ȱ����ϰ\n"NOR;
			if( n == 1 ) str2 += HBRED"��\n"NOR;
			if( n == 2 ) str2 += HBRED"���\n"NOR;
			if( n == 3 ) str2 += HBRED"����\n"NOR;
			if( n == 4 ) str2 += HBRED"�����\n"NOR;
			if( n == 5 ) str2 += HBRED"������\n"NOR;
			if( n == 6 ) str2 += HBRED"������\n"NOR;
			if( n == 7 ) str2 += HBRED"������\n"NOR;
			if( n == 8 ) str2 += HBRED"������\n"NOR;
			if( n == 9 ) str2 += HBRED"������\n"NOR;
			if( n >  9 ) str2 += HBRED"������\n"NOR;
		}
		str2 += "��������������������������������������������������������\n";
	}

	write( str2 );	
	return 1;
}

int help(object me)
{
	string *file,	str, bname;
	int i, j=0;

	file = get_dir("/d/music/book/");

	if( sizeof(file) > 0 ) {
		file  = filter_array(file, (: sort_skill :) );
		j = sizeof(file);
	}



	if( j > 0 ) {
		str = "\n��������������������������������������������������������\n";
		for( i=0; i < j; i++ ) {
			bname = call_other("/d/music/book/" + file[i], "book_name");
			if( bname ) str += " ��"+bname+"��";
			else str +=" ����������";
			str += "("+YEL+replace_string(file[i], ".c", "")+NOR+")\n";
		}
	}

write(@HELP
ָ���ʽ : music
���ָ�����������ʾĿǰ�������ܵȼ����Ѿ�ѧ��ĵ������ס�
Ŀǰ���ŵ������У�
HELP);
		write(str);
		write("��������������������������������������������������������\n");

	return 1;
}