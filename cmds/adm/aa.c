int main(object me)
{
    object *all_objs;
    int size;

    all_objs = objects();
    size = sizeof(all_objs);

    tell_object(me,sprintf("�ڴ���һ���У�%d �������\n",size));
    return 1;
}  
