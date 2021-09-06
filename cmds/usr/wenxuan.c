// wenxuan.c
/*

   by snowman@SJ 23/04/1999

   Copyright 1997-1999 ShuJian MUD Wizard Group.
   All rights reserved.

Modify by bbb 2000/12/16 ,wenxuan->homepage mysql
*/

inherit F_CLEAN_UP;

#include <ansi.h>
#include <localtime.h>
#include <database.h>
#include <mudlib.h>

#define Data_Base_Online

// ʡȱ����ѡĿ¼��
#define WENXUAN_DIR     "/data/wenxuan/"
#define TEXT_LINE       "����������������������������������������������������������������������������������\n"

int help(object me);
int list(object me, int y, int m);
int read_note(object me, int number, int m, int y);

/* ������*/
int main(object me, string arg)
{
        mapping *notes;
        object board;
        string *file, str, msg, text; //text�ǵ�webȥ�����ݲ���
        int i, j, num, number,m,y;
        
        mixed userid;


        // ���⡣
        tell_object(me,HIW"\n��"NOR + MUD_NAME + HIW"��ѡ��ȫ"NOR + HIW"��"NOR"��");

        // ��ȡĿǰ�����(y)���·�(m)��
        m = localtime(time())[LT_MON] + 1;
        y = localtime(time())[LT_YEAR];

        file = get_dir(WENXUAN_DIR);
        i = sizeof(file);

        // �����κβ�����������б�
        if (!arg) {
                if (!i) return notify_fail("������ʱ��û����ѡ��\n");
                else list(me, y, m);
        }

        // ���������
        else if (arg == "?") return help(me);

        // �г�������¼����ѡ����ݡ�
        else if(arg == "all"){
                str = "Ŀǰ�� ";
                while(i--) str += "[" + file[i] + "��] ";
                tell_object(me, str + "����ѡ��\n");
        }

        // ����������ݺ��·ݡ�
        else if(sscanf(arg, "%d %d %d", number, m, j)==3){
                if(m < 1 || m > 12)
                        return notify_fail("�С�" + chinese_number(m) + "�¡�����·���\n");
                if(j < 1970 || j > y )
                        return notify_fail("��û�� [" + j + "] �������ѡ�ء�\n");
                // �б�
                if(number == 0)
                        list(me, j, m);
                // �Ķ���
                else read_note(me, number, m, j);
        }

        // ���������·ݡ�
        else if(sscanf(arg, "%d %d", number, m)==2){
                if(m < 1 || m > 12)
                        return notify_fail("�С�" + chinese_number(m) + "�¡�����·���\n");
                // �б�
                if(number == 0)
                        list(me, y, m);
                // �Ķ���
                else read_note(me, number, m, y);
        }

        // ������Ϊ��ţ��Ķ���ѡ��
        else if(sscanf(arg, "%d", number) == 1)
                read_note(me, number, m, y);

        // �����ѡ��
        else if(sscanf(arg, "add %d", num) == 1){
                // Player���ɶ���ѡ���в�����
                if(!wizardp(me))
                        return help(me);

                if(num < 1)
                        return notify_fail("���Ա�Ų���ȷ��\n");

                if(!objectp(board = present("board", environment(me))))
                        return notify_fail("����û�����԰塣\n");

                if( !notes = board->query("notes") || !arrayp(notes) )
                        return notify_fail("���԰�������顣\n");

                i = sizeof(notes);
                if( num > i) return notify_fail("�˰��Ϲ��� "+sizeof(notes)+" �����ԣ���������ȷ�ı�š�\n");

                num--;
                number = 1;

                str = WENXUAN_DIR + y + "/" + m + "/";

                // ���·ݻ�����ݡ�
                if(!get_dir(str)) assure_file(str + number + ".w");

                else  number = sizeof(get_dir(str + "*.w")) + 1;

                // �������⡣
                msg = sprintf("%-=36s %18s (%s)\n",notes[num]["title"], notes[num]["author"],ctime(notes[num]["time"])[0..15]);

                // д�� .w ��ѡ�ļ���
                write_file(str + number + ".w", msg + TEXT_LINE + notes[num]["msg"] , 1);
                
                // ���뵽���ݿ�
                // send to web site.
                        userid = explode(notes[num]["author"],"(");
                        userid = replace_string(userid[1],")","");
                        
   			text  = (sprintf("[color=red]%s �� %s ���� �������� %s �� %s[/color]\n",notes[num]["author"],
				"/cmds/usr/time.c"->Ctime(notes[num]["time"]),CHINESE_MUD_NAME,
				board->query("name")) + notes[num]["msg"]);				  
				                  
                       if (BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "INSERT INTO izz_text_soft ( 
				soft_name, soft_keyword, soft_download_url, soft_is_commend, 
				soft_grade, soft_type, soft_note, soft_author, soft_relation_url, 
				soft_category_id, soft_class_id, soft_img, soft_byuser, soft_user_id, 
				soft_size, soft_date, soft_hits_day, soft_display ) 
				VALUES
				 ( '"+notes[num]["title"]+"', '��ѡ', '"+userid+"@"+INTERMUD_MUD_NAME+"', '0', '3', 'ԭ��', 
				 '"+text+"', '�齣�ٷ�վ', 'http://www.mymud.com', '7', 
				 '15', 'N/A', 'Linux', '17', 'N/A', '"+"/cmds/usr/news.c"->Ctime(notes[num]["time"])+"', '"+"/cmds/usr/news.c"->Ctime(notes[num]["time"])+"', '1' )"))

			{	
				write ("��ѡ��������ҳ.......�ɹ�!\n");
				if (!dbquery("update Users set U_Credit = U_Credit +50 where U_Username = \"" + userid + "\""))
					write("��ӵ���ҳ��̶������ ......... ������ϣ�50 �ֽ���δ�ܳɹ����ӡ�\n");
				else
					write("��ӵ���ҳ��̶������ ......... ������ϣ������Ѿ������齣���� 50 �㡣\n");
	                }
                        else {
                                write("��ӵ���ҳ������ ......... ����ʧ�ܣ���֪ͨ LinuX ��������⡣\n");
                        }
          
                return notify_fail("�㽫�� " + (num + 1) + " �����Է�����ѡ " + y + " �� " + m + " �µ� " + number + " ��....Ok��\n");
        }

        // ɾ����ѡ��
        else if(sscanf(arg, "del %s", arg) == 1){
                // Player���ɶ���ѡ���в�����
                if(!wizardp(me)) return help(me);

                if( sscanf(arg, "%d %d %d", num, m, y) != 3 )
                        if( sscanf(arg, "%d %d", num, m) != 2 )
                                if( sscanf(arg, "%d", num) != 1 )
                                        if( sscanf(arg, "%s", msg) != 1 )
                                                return notify_fail("ָ���ʽ��dlwx <���|all> [�·�] [���]\n");

                str = WENXUAN_DIR + y + "/" + m + "/";

                // ����û����ѡ��
                if(!get_dir(str))
                        return notify_fail(" " + y + " �� " + m + " ��û����ѡ��\n");

                // ɾ������������ѡ��
                else if(msg && msg == "all"){
                        // ɾ����Ŀ¼�������ļ���
                        rm(str);
                        // ɾ����Ŀ¼��
                        rmdir(str);
                        return notify_fail("�㽫 " + y + " �� " + m + " ��������ѡ��ɾ����....Ok��\n");
                }

                if(num < 1)
                        return notify_fail("��ѡ��Ų���ȷ��\n");

                if(file_size(str + num + ".w") <= 0)
                        return notify_fail(" " + y + " �� " + m + " ��û������ָ����ƪ��ѡ��\n");

                i = sizeof(get_dir(str));

                // ɾ������ѡ�ļ���
                rm(str+num+".w");

                // ����������ѡ�ļ���
                if(num < i)
                        for(j = num + 1; j <= i; j++)
                                if(file_size(str + j + ".w") > 0){
                                        cp(str + j + ".w", str + (j - 1) + ".w");
                                        rm(str + j + ".w");
                                }

                return notify_fail("�㽫 "+y+" �� "+m+" �µ� " + num + " ����ѡɾ����....Ok��\n");
        }

        else help(me);

        return 1;
}

/* �г���ѡ��*/
// m = �·ݣ� y = ���
int list(object me, int y, int m)
{
        string *note;
        string str;
        int i, j;

        tell_object(me, y + " �� " + m + " ��");

        // ��ȡ�ļ���Ŀ��
        note = get_dir(WENXUAN_DIR + y + "/" + m + "/*.w");
        i = sizeof(note);

        if (!i){
                write("��û���κ���ѡ��\n");
                return 0;
        }

        write("����"+chinese_number(i)+"����ѡ��\n");
        str = TEXT_LINE;

        // ��ʼ�б�
        for(j = 0; j < i; j++)
                str += " [" + (j + 1) + "] "+read_file(WENXUAN_DIR + y + "/" + m + "/" + (j + 1) + ".w", 1, 1);

        str += TEXT_LINE;
        str += HIW"���� help wenxuan �� wenxuan ? �鿴ʹ�÷�����\n"NOR;
        // �����
        me->start_more(str);
        return 1;

}

/* �Ķ���ѡ��*/

// number = ƪ����m = �·ݣ� y = ���
int read_note(object me, int number, int m, int y)
{
        string *note;
        int i;

        tell_object(me, y + " �� " + m + " ��");
        note = get_dir(WENXUAN_DIR + y + "/" + m + "/*.w");
        i = sizeof(note);

        if (!i){
                write("��û���κ���ѡ��\n");
                return 0;
        }

        if( number < 1 || number > i ){
                write("Ŀǰ��û������Ҫ������ƪ��ѡ��\n");
                return 0;
        }

        write("�ĵ�" + chinese_number(number) + "����ѡ��\n\n");

        // �����
        me->start_more( " [" + number + "] " + read_file(WENXUAN_DIR + y + "/" + m + "/" + number + ".w"));
        return 1;

}


int help(object me)
{
        write(@HELP
ָ���ʽ��

wenxuan all                  : �г�����ѡ����ݡ�
wenxuan                      : �г�������ѡ��
wenxuan <���>               : �Ķ����´˱�ŵ����¡�
wenxuan 0 <�·�>             : �г�������·���ѡ��
wenxuan <���> <�·�>        : �Ķ����·ݴ˱�ŵ����¡�
wenxuan 0 <�·�><���>       : �г�����ݴ��·���ѡ��
wenxuan <���> <�·�> <���> : �Ķ�����ݴ��·ݴ˱�ŵ����¡�

��ʦר�ã�

wenxuan add <���Ա��> ��ѡһ�� add, �Զ�����ҳ������
wenxuan del <���|all> [�·�] [���]

wenxuan del all                    : ɾ������������ѡ��
wenxuan del <���>                 : ɾ�����´˱�ŵ���ѡ��
wenxuan del <���> [�·�]          : ɾ�����·ݴ˱�ŵ���ѡ��
wenxuan del <���> [�·�] [���]   : ɾ������ݴ��·ݴ˱�ŵ���ѡ��
��ѡɾ���������Զ�ɾ����ҳ�����������б�Ҫ��ȥ��ҳɾ����


        Snowman@SJ 06/04/1999

        Copyright 1997-1999 ShuJian MUD Wizard Group.
        All rights reserved.

        Visit our Homepage at - www.mymud.com

HELP);

    return 1;
}
