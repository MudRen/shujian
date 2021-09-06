//plan.c by XiaoYao 2/8/2k
                        
inherit F_DBASE;

#include <ansi.h>
int help(object me);
void do_plan(string me,string path, string text);
void do_note(string me,string path, string text);
void do_user_motd(object me,string path, string text);
void do_wiz_motd(object me,string path, string text);

void create() 
{
        seteuid(getuid());
        set("channel_id", "�ƻ�����");
}

int main(object me,string arg)
{
        string target,path;
        if(!user_path(geteuid(me)))
                return notify_fail("�㲢û�м�Ŀ¼\n");
        if(!arg){
                path = user_path(geteuid(me)) + "wiz_plan";
                write(CLR"");
                if( file_size(path) > 0 ){       
                 write(HIW"Ŀǰ�ļƻ���:\n"NOR);
                 write(read_file(path));
                 }
                write(HIY"\n\n�༭�Լ��ļƻ���\n"NOR);
                me->edit((: do_plan, geteuid(me),path :));
                return 1;
                }
        if (arg == "none")
        {
                path = user_path(geteuid(me)) + "wiz_plan";
                if( file_size(path) <= 0 )
                 return notify_fail("��û�мƻ�������\n");
                rm(path);
                write("����ƻ�����\n");
                CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)����ƻ�����%s��", me->query("name"),me->query("id"), ctime(time()) ) );
                log_file("wiz_log/wiz_plan",
                        sprintf("%s(%s)����ƻ�����%s\n"NOR,me->query("name"),me->query("id"), ctime(time()) ));
                return 1;
        }
        if(arg == "note none")
        {
                path = user_path(geteuid(me)) + "wiz_note";
                if( file_size(path) <= 0 )
                 return notify_fail("��û�����Լ�¼ม�\n");
                rm(path);
                write("������Լ�¼��\n");
                return 1;
        }
        if(arg == "user none")
        {
           path = "/adm/etc/motd";

           if(wizhood(me) != "(admin)" && wizhood(me) != "(arch)" )
              return notify_fail("ֻ�д���ʦ���ϲ���ɾ��ÿ��ѶϢ\n");
           if( file_size(path) <= 0)
             return notify_fail("û��ʹ���߹���!\n");
           rm(path);
           write("���ʹ���߹���\n");
           CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)���ʹ���߹�����%s��", me->query("name"),me->query("id"), ctime(time()) ) );
           log_file("wiz_log/user_motd",
                sprintf(HIC"%s(%s)���ʹ���߹�����%s\n"NOR,me->query("name"),me->query("id"), ctime(time()) ));
           return 1;
        }
if(arg == "wiz none")
        {
          path = "/adm/etc/wiz_motd";
          if(wizhood(me) != "(admin)")
            return notify_fail("ֻ���������ɾ����ʦÿ��ѶϢ\n");
          if( file_size(path) <= 0)
            return notify_fail("û����ʦ����!\n");
           rm(path);
           write("�����ʦ����\n");
           CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)�����ʦ������%s��", me->query("name"),me->query("id"), ctime(time()) ) );
           log_file("wiz_log/wiz_motd",
                        sprintf(HIC"%s(%s)�����ʦ������%s\n"NOR,me->query("name"),me->query("id"), ctime(time()) ));
           return 1;
        }
        if(arg == "user motd"){
         path = "/adm/etc/motd";
         if( file_size(path) > 0){
                write(CLR""+HIW"Ŀǰ��ʹ���߹���\n"NOR);
                write(read_file(path));
}else
                write(CLR""+HIR"Ŀǰû��ʹ���߹���\n"NOR);
                
        if(wizhood(me) == "(admin)" || wizhood(me) == "(arch)" ){ 
         write(HIY"\n�༭ʹ���߹���\n\n"NOR);
         me->edit((: do_user_motd ,me ,path :));
         }
         return 1;
        }
        if(arg == "wiz motd"){
          if(wizhood(me) != "(admin)")
            return notify_fail("ֻ��������ܹ�����ʦÿ��ѶϢ\n");
          else path = "/adm/etc/wiz_motd"; //����ͨ����ָ������

         write("�༭��ʦ����\n");
            if( file_size(path) > 0){
             write(CLR""+HIW"Ŀǰ����ʦ����\n"NOR);
             write(read_file(path));
                                            }
           write(HIY"\n�༭��ʦÿ�չ���\n\n"NOR);
      me->edit((: do_wiz_motd , me ,path:));
            return 1;
            }
       if(sscanf(arg,"-w %s",target) == 1){
           target = replace_string(arg,"-w ","");
           if( wiz_level(target) == 0){
             write("��������ʦ,����Ҫʹ�á��ƻ�����������!\n");
             return 1;
           }else path = user_path(target) + "wiz_plan";
           if(file_size(path) > 0){
            write(HIY+target+"�ļƻ��� :\n"NOR);
            me->start_more(read_file(path));
           }else write(target+"��û�мƻ���!!\n"); 
           return 1;
        }    
        if(sscanf(arg,"-n %s",target) == 1){
           target = replace_string(arg,"-n ","");
           if( wiz_level(target) == 0)
            {
               write("��������ʦ,����Ҫʹ�á��ƻ�����������!\n");
       return 1;
             }else path = user_path(target) + "wiz_note";

           write("��"+target+"�����ʦ����\n");
            me->edit((: do_note , target ,path: ));
            return 1;
                         }
        if(sscanf(arg, "%s",arg) == 1 ){
                
                if(SECURITY_D->get_status(me) != "(arch)"
                        && SECURITY_D->get_status(me) != "(admin)" )
                                return notify_fail("ֻ�� (arch) ���ϵ���ʦ����ָ������\n");
                if( wizhood(arg) == "(player)"){
                        write("��������ʦ,����Ҫʹ�á��ƻ�����������!\n");
                        return 1;
                }else path = user_path(arg) + "wiz_plan";
                me->edit((: do_plan, arg ,path:));
                return 1;
                }
        else return help(me);
        return 1;
}


void do_plan(string planer,string path, string text)
{
        string msg;
        msg = "�᰸�� ("+this_player()->query("id")+") "+ctime(time()) +"\n"+text;
        if (planer)
        {
           write_file(path,msg,1);
           write(HIW"�ƻ����趨��ɡ�\n"NOR);
           CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)�ƻ����趨�����%s��", this_player()->query("name"),geteuid(this_player()), ctime(time()) ) );
           log_file("wiz_log/wiz_plan",
                        sprintf(HIC"%s(%s)�ƻ����趨�����%s\n"NOR,this_player()->query("name"),geteuid(this_player()), ctime(time()) ));
        }
        else{
           write(HIR"�ƻ����趨ʧ�ܡ�\n"NOR);
           CHANNEL_D->do_channel( this_object(), "sys",
sprintf(HIR"%s(%s)�ƻ����趨ʧ����%s��"NOR, this_player()->query("name"),geteuid(this_player()), ctime(time()) ) );
           log_file("wiz_log/wiz_plan",
                        sprintf(HIR"%s(%s)�ƻ����趨ʧ����%s\n"NOR,this_player()->query("name"),geteuid(this_player()), ctime(time()) ));
       }
}

void do_note(string planer,string path, string text)
{
        object me = this_player();
        string msg;
        msg = "������:("+me->query("id")+") "+ctime(time())+"\n"NOR+ text;

        if (planer)
        {
                write_file(path,msg);
                write(HIW"������ϡ�\n"NOR);
                CHANNEL_D->do_channel( this_object(), "cic",
                sprintf("%s(%s)���Ը�%s��%s��", me->query("name"),me->query("id"),planer,ctime(time()) ) );
                log_file("wiz_log/note_message",
                        sprintf("%s(%s)���Ը�%s��%s\n",me->query("name"),me->query("id"),planer, ctime(time()) ));
}
        else{
            write(HIR"����ʧ�ܡ�\n"NOR);
            CHANNEL_D->do_channel( this_object(), "cic",
                sprintf(HIR"%s(%s)���Ը�%sʧ����%s��"NOR, me->query("name"),me->query("id"),planer,ctime(time()) ) );
             log_file("wiz_log/note_message",
                     sprintf(HIR"%s(%s)���Ը�%sʧ����%s\n"NOR,me->query("name"),me->query("id"),planer, ctime(time()) ));
        }
}

void do_user_motd(object me,string path,string text)
{
        string msg;
        msg = HIW"������:("+me->query("id")+") "NOR+ctime(time())+"\n"+text;      
 
        if(me)
        {
          write_file(path,msg);
          write("ʹ���߹������\n");
          CHANNEL_D->do_channel( this_object(), "sys",
          sprintf("%s(%s)��%s����ʹ���߹��档", me->query("name"),me->query("id"),ctime(time()) ) );
          log_file("wiz_log/user_motd",
                        sprintf("%s(%s)��%s����ʹ���߹���\n",me->query("name"),me->query("id"), ctime(time()) ));

        }else{
            write("����ʧ��\n");
          CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)��%s����ʹ���߹���ʧ�ܡ�", me->query("name"),me->query("id"),ctime(time()) ) );
          log_file("wiz_log/user_motd",
                        sprintf(HIR"%s(%s)��%s����ʹ���߹���ʧ��\n"NOR,me->query("name"),me->query("id"), ctime(time()) ));
         }
}
void do_wiz_motd(object me,string path,string text)
{
       string msg;
       msg = HIW"������:("+me->query("id")+") "NOR+ctime(time())+"\n"+text;

       if(me)
       {
        write_file(path,msg);
        write("��ʦ�������\n");
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)��%s������ʦ���档", me->query("name"),me->query("id"),ctime(time()) ) );
        log_file("wiz_log/wiz_motd",
                        sprintf("%s(%s)��%s������ʦ����\n",me->query("name"),me->query("id"), ctime(time()) ));
        }else{
           write("����ʧ��\n");
           CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)��%s������ʦ����ʧ�ܡ�", me->query("name"),me->query("id"),ctime(time()) ) );
           log_file("wiz_log/wiz_motd",
                        sprintf(HIR"%s(%s)��%s������ʦ����ʧ��\n"NOR,me->query("name"),me->query("id"), ctime(time()) ));
          }
}

int help(object me)
{
 write(@HELP
ָ���ʽ : plan           =>���Ӳ���ʱ�Ǳ༭�Լ��ļƻ���
           plan    [none] => ����Լ��ļƻ���
           plan    [note none] => �������
           plan -n [�뽻�����Ե���ʦ��id] => ���Ը�������ʦ
           plan    [user motd] => �Ķ�ʹ����ÿ�չ���
           plan -w [WIZ id] =>�ۿ���ʦ�ƻ�

�����Ǵ���ʦ���ϲſ���ʹ�õĲ���:
           plan    [�뽻���������ʦ��id] => ���������ָ������ʦ
           plan    [user motd] => ����ʹ����ÿ�չ���
           plan    [user none] => ���ʹ���߹���
           plan    [wiz motd]  => ��ʦ����
           plan    [wiz none]  => �����ʦ����
��;:
��ʾ�Լ����߸�������,����ʦ���ϻ�ʹ�����ָ��ָ���������ʦ
����������ʱ�Ϳ������½��������Լ���������,����ʦ���Ϲ�����
�����֮ͬǰ�Ĺ���һ�����,ֻ��ʹ��noneָ��ŻὫ�������,��
���ƻ���Ҳ��,������С��ʹ��none����,����ɾ����Ҫ��¼!

���ָ����Ա༭�Լ��ļƻ���plan none ��������趨��

HELP
    );
  return 1;
}

